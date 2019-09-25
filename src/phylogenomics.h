#ifndef __JACKALOPE_PHYLOGENOMICS_H
#define __JACKALOPE_PHYLOGENOMICS_H


/*
 ********************************************************

 Methods for evolving chromosomes along phylogenies / gene trees

 ********************************************************
 */


#include "jackalope_config.h" // controls debugging and diagnostics output

#include <RcppArmadillo.h>
#include <vector>  // vector class
#include <string>  // string class
#include <algorithm>  // lower_bound, sort
#include <deque>  // deque
#include <random>  // exponential_distribution
#include <progress.hpp>  // for the progress bar
#ifdef _OPENMP
#include <omp.h>  // omp
#endif

#include "jackalope_types.h"  // integer types
#include "var_classes.h"  // Var* classes
#include "mutator.h"  // TreeMutator
#include "alias_sampler.h" // alias sampling
#include "pcg.h" // pcg sampler types


using namespace Rcpp;






/*
 Phylogenetic tree info for one chromosome range.

 * Do all input checks outside this object's creation!
 * `edges` is converted to C++ indices inside this object's constructor.

 */
struct PhyloTree {

    std::vector<double> branch_lens;
    arma::Mat<uint64> edges;
    std::vector<std::string> tip_labels;
    uint64 start;
    uint64 end;
    std::vector<uint64> ends;  // (non-inclusive) `end` values for each tree tip
    uint64 n_tips;             // # tips = # variants
    uint64 n_edges;            // # edges = # connections between nodes/tips

    PhyloTree() {}
    PhyloTree(
        const std::vector<double>& branch_lens_,
        const arma::Mat<uint64>& edges_,
        const std::vector<std::string>& tip_labels_,
        const uint64& start_,
        const uint64& end_
    )
        : branch_lens(branch_lens_),
          edges(edges_),
          tip_labels(tip_labels_),
          start(start_),
          end(end_),
          ends(tip_labels_.size(), end_),
          n_tips(tip_labels_.size()),
          n_edges(edges_.n_rows) {

        // From R to C++ indices
        edges -= 1;
    }
    PhyloTree(const PhyloTree& other)
        : branch_lens(other.branch_lens), edges(other.edges),
          tip_labels(other.tip_labels), start(other.start), end(other.end),
          ends(other.ends), n_tips(other.n_tips),
          n_edges(other.n_edges) {}

    PhyloTree& operator=(const PhyloTree& other) {
        branch_lens = other.branch_lens;
        edges = other.edges;
        tip_labels = other.tip_labels;
        start = other.start;
        end = other.end;
        ends = other.ends;
        n_tips = other.n_tips;
        n_edges = other.n_edges;
        return *this;
    }

};


/*
 Phylogenetic tree info for one entire chromosome.

 The `trees` field contains the actual phylogeny information.
 It is a vector of `PhyloTree` objects, to allow for
 multiple phylogenies, as will be the case when recombination is included.
 If not including recombination, `trees` will simply be of length 1.

 */


class PhyloOneChrom {

public:
    std::vector<PhyloTree> trees;
    std::vector<VarChrom*> tip_chroms;      // pointers to final VarChrom objects
    std::vector<std::deque<uint8>> rates;   // rate indices (Gammas + invariants) for tree
    TreeMutator mutator;                    // to do the mutation additions across tree
    uint64 n_tips;                          // number of tips (i.e., variants)


    PhyloOneChrom() {}
    /*
     Construct just tree and mutator info, when no VarSet info yet available.
     Used in `fill_tree_mutator` method below.
     */
    PhyloOneChrom(
        const std::vector<uint64>& n_bases_,
        const std::vector<std::vector<double>>& branch_lens_,
        const std::vector<arma::Mat<uint64>>& edges_,
        const std::vector<std::vector<std::string>>& tip_labels_,
        const TreeMutator& mutator_base
    )
        : trees(edges_.size()),
          tip_chroms(),
          rates(tip_labels_[0].size()),
          mutator(mutator_base),
          n_tips(tip_labels_[0].size()),
          recombination(branch_lens_.size() > 1)
    {

        uint64 n_trees = edges_.size();

        if (n_bases_.size() != branch_lens_.size() ||
            n_bases_.size() != edges_.size() ||
            n_bases_.size() != tip_labels_.size()) {
            std::string err_msg = "\nVectors for number of bases, branch lengths, edges";
            err_msg += ", and tip labels do not all have the same length.";
            throw(Rcpp::exception(err_msg.c_str(), false));
        }

        // Fill `trees`:
        uint64 start_ = 0;
        uint64 end_ = 0; // note: non-inclusive end point
        for (uint64 i = 0; i < n_trees; i++) {
            end_ += n_bases_[i];
            if (i > 0) start_ += n_bases_[i-1];
            trees[i] = PhyloTree(branch_lens_[i], edges_[i], tip_labels_[i],
                                 start_, end_);
        }

    }

    /*
     Set variant info:
     */
    void set_var_info(VarSet& var_set, const uint64& chrom_ind) {

        uint64 n_vars = var_set.size();

        // Filling in pointers:
        tip_chroms.clear();
        tip_chroms.reserve(n_vars);
        for (uint64 i = 0; i < n_vars; i++) {
            tip_chroms.push_back(&var_set[i][chrom_ind]);
        }

        return;

    }


    /*
     Evolve all trees.
     */
    int evolve(pcg64& eng, Progress& prog_bar);



    /*
     Fill tree and mutator info from an input list and base mutator object
    */
    void fill_tree_mutator(const List& genome_phylo_info, const uint64& i,
                           const TreeMutator& mutator_base);




private:


    bool recombination;


    /*
     Evolve one tree.
     */
    int one_tree(PhyloTree& tree, pcg64& eng, Progress& prog_bar);


    /*
     Reset for a new tree:
     */
    int reset(const PhyloTree& tree,
              pcg64& eng,
              Progress& prog_bar) {

        const uint64& start(tree.start);
        const uint64& end(tree.end);

        if (tree.n_tips == 0) {
            throw(Rcpp::exception("\n# tips == zero is non-sensical.", false));
        }

        // Create rates:
        if (rates.size() != this->n_tips) rates.resize(this->n_tips);
        uint64 root = tree.edges(0,0); // <-- should be index to root of tree
        // Generate rates for root of tree (`status` is -1 if user interrupts process):
        int status = mutator.new_rates(start, end, rates[root], eng, prog_bar);
        // The rest of the nodes/tips will have rates based on parent nodes
        // as we progress through the tree.

        return status;
    }


    /*
     Clear info from `rates` for `b1` if it's no longer needed, to free up
     some memory.
     */
    void clear_branches(const uint64& b1,
                        const uint64& i,
                        const PhyloTree& tree) {
        bool do_clear;
        if (i < (tree.edges.n_rows - 1)) {
            // Is it absent from any remaining items in the first column?
            do_clear = ! arma::any(tree.edges(arma::span(i+1, tree.edges.n_rows - 1),
                                              0) == b1);
        } else do_clear = true;
        if (do_clear) {
            rates[b1].clear();
            clear_memory<std::deque<uint8>>(rates[b1]);
        }
        return;
    }

};







/*
 Phylogenetic tree info for all chromosomes in a genome.

 */
class PhyloInfo {
public:

    std::vector<PhyloOneChrom> phylo_one_chroms;

    PhyloInfo(const List& genome_phylo_info, const TreeMutator& mutator_base);

    XPtr<VarSet> evolve_chroms(
            SEXP& ref_genome_ptr,
            const uint64& n_threads,
            const bool& show_progress);



};








#endif
