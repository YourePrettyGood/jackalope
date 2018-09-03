// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "gemino_types.h"
#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// merge_sequences
void merge_sequences(SEXP ref_genome_);
RcppExport SEXP _gemino_merge_sequences(SEXP ref_genome_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    merge_sequences(ref_genome_);
    return R_NilValue;
END_RCPP
}
// filter_sequences
void filter_sequences(SEXP ref_genome_, const uint32& min_seq_size, const double& out_seq_prop);
RcppExport SEXP _gemino_filter_sequences(SEXP ref_genome_SEXP, SEXP min_seq_sizeSEXP, SEXP out_seq_propSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type min_seq_size(min_seq_sizeSEXP);
    Rcpp::traits::input_parameter< const double& >::type out_seq_prop(out_seq_propSEXP);
    filter_sequences(ref_genome_, min_seq_size, out_seq_prop);
    return R_NilValue;
END_RCPP
}
// create_genome_
SEXP create_genome_(const uint32& n_seqs, const double& len_mean, const double& len_sd, std::vector<double> pi_tcag, const uint32& n_cores);
RcppExport SEXP _gemino_create_genome_(SEXP n_seqsSEXP, SEXP len_meanSEXP, SEXP len_sdSEXP, SEXP pi_tcagSEXP, SEXP n_coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type n_seqs(n_seqsSEXP);
    Rcpp::traits::input_parameter< const double& >::type len_mean(len_meanSEXP);
    Rcpp::traits::input_parameter< const double& >::type len_sd(len_sdSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    rcpp_result_gen = Rcpp::wrap(create_genome_(n_seqs, len_mean, len_sd, pi_tcag, n_cores));
    return rcpp_result_gen;
END_RCPP
}
// rando_seqs
std::vector<std::string> rando_seqs(const uint32& n_seqs, const double& len_mean, const double& len_sd, NumericVector pi_tcag, const uint32& n_cores);
RcppExport SEXP _gemino_rando_seqs(SEXP n_seqsSEXP, SEXP len_meanSEXP, SEXP len_sdSEXP, SEXP pi_tcagSEXP, SEXP n_coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type n_seqs(n_seqsSEXP);
    Rcpp::traits::input_parameter< const double& >::type len_mean(len_meanSEXP);
    Rcpp::traits::input_parameter< const double& >::type len_sd(len_sdSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    rcpp_result_gen = Rcpp::wrap(rando_seqs(n_seqs, len_mean, len_sd, pi_tcag, n_cores));
    return rcpp_result_gen;
END_RCPP
}
// get_precleavage_lens
std::vector<uint32> get_precleavage_lens(const std::vector<std::string>& seqs);
RcppExport SEXP _gemino_get_precleavage_lens(SEXP seqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type seqs(seqsSEXP);
    rcpp_result_gen = Rcpp::wrap(get_precleavage_lens(seqs));
    return rcpp_result_gen;
END_RCPP
}
// expand_seqs
std::vector<std::string> expand_seqs(const std::vector<std::string>& seqs);
RcppExport SEXP _gemino_expand_seqs(SEXP seqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type seqs(seqsSEXP);
    rcpp_result_gen = Rcpp::wrap(expand_seqs(seqs));
    return rcpp_result_gen;
END_RCPP
}
// digest_var_set
SEXP digest_var_set(SEXP var_set_, const std::vector<std::string>& bind_sites, const std::vector<uint32>& len5s, const uint32& chunk_size, const uint32& n_cores);
RcppExport SEXP _gemino_digest_var_set(SEXP var_set_SEXP, SEXP bind_sitesSEXP, SEXP len5sSEXP, SEXP chunk_sizeSEXP, SEXP n_coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type bind_sites(bind_sitesSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type len5s(len5sSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type chunk_size(chunk_sizeSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    rcpp_result_gen = Rcpp::wrap(digest_var_set(var_set_, bind_sites, len5s, chunk_size, n_cores));
    return rcpp_result_gen;
END_RCPP
}
// digest_ref
SEXP digest_ref(SEXP ref_genome_, const std::vector<std::string>& bind_sites, const std::vector<uint32>& len5s, const uint32& chunk_size, const uint32& n_cores);
RcppExport SEXP _gemino_digest_ref(SEXP ref_genome_SEXP, SEXP bind_sitesSEXP, SEXP len5sSEXP, SEXP chunk_sizeSEXP, SEXP n_coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type bind_sites(bind_sitesSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type len5s(len5sSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type chunk_size(chunk_sizeSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    rcpp_result_gen = Rcpp::wrap(digest_ref(ref_genome_, bind_sites, len5s, chunk_size, n_cores));
    return rcpp_result_gen;
END_RCPP
}
// phylo_info_to_trees
SEXP phylo_info_to_trees(List genome_phylo_info);
RcppExport SEXP _gemino_phylo_info_to_trees(SEXP genome_phylo_infoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type genome_phylo_info(genome_phylo_infoSEXP);
    rcpp_result_gen = Rcpp::wrap(phylo_info_to_trees(genome_phylo_info));
    return rcpp_result_gen;
END_RCPP
}
// phylo_info_to_trees_chunk
SEXP phylo_info_to_trees_chunk(List genome_phylo_info);
RcppExport SEXP _gemino_phylo_info_to_trees_chunk(SEXP genome_phylo_infoSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type genome_phylo_info(genome_phylo_infoSEXP);
    rcpp_result_gen = Rcpp::wrap(phylo_info_to_trees_chunk(genome_phylo_info));
    return rcpp_result_gen;
END_RCPP
}
// evolve_seqs
void evolve_seqs(SEXP& var_set_ptr, SEXP& sampler_base_ptr, SEXP& phylo_info_ptr, const std::vector<uint32>& seq_inds, const std::vector<arma::mat>& gamma_mats, const bool& show_progress);
RcppExport SEXP _gemino_evolve_seqs(SEXP var_set_ptrSEXP, SEXP sampler_base_ptrSEXP, SEXP phylo_info_ptrSEXP, SEXP seq_indsSEXP, SEXP gamma_matsSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP& >::type var_set_ptr(var_set_ptrSEXP);
    Rcpp::traits::input_parameter< SEXP& >::type sampler_base_ptr(sampler_base_ptrSEXP);
    Rcpp::traits::input_parameter< SEXP& >::type phylo_info_ptr(phylo_info_ptrSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type seq_inds(seq_indsSEXP);
    Rcpp::traits::input_parameter< const std::vector<arma::mat>& >::type gamma_mats(gamma_matsSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    evolve_seqs(var_set_ptr, sampler_base_ptr, phylo_info_ptr, seq_inds, gamma_mats, show_progress);
    return R_NilValue;
END_RCPP
}
// evolve_seqs_chunk
void evolve_seqs_chunk(SEXP& var_set_ptr, SEXP& sampler_base_ptr, SEXP& phylo_info_ptr, const std::vector<uint32>& seq_inds, const std::vector<arma::mat>& gamma_mats, const bool& show_progress);
RcppExport SEXP _gemino_evolve_seqs_chunk(SEXP var_set_ptrSEXP, SEXP sampler_base_ptrSEXP, SEXP phylo_info_ptrSEXP, SEXP seq_indsSEXP, SEXP gamma_matsSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP& >::type var_set_ptr(var_set_ptrSEXP);
    Rcpp::traits::input_parameter< SEXP& >::type sampler_base_ptr(sampler_base_ptrSEXP);
    Rcpp::traits::input_parameter< SEXP& >::type phylo_info_ptr(phylo_info_ptrSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type seq_inds(seq_indsSEXP);
    Rcpp::traits::input_parameter< const std::vector<arma::mat>& >::type gamma_mats(gamma_matsSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    evolve_seqs_chunk(var_set_ptr, sampler_base_ptr, phylo_info_ptr, seq_inds, gamma_mats, show_progress);
    return R_NilValue;
END_RCPP
}
// TN93_rate_matrix
arma::mat TN93_rate_matrix(const std::vector<double>& pi_tcag, const double& alpha_1, const double& alpha_2, const double& beta, const double& xi);
RcppExport SEXP _gemino_TN93_rate_matrix(SEXP pi_tcagSEXP, SEXP alpha_1SEXP, SEXP alpha_2SEXP, SEXP betaSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const double& >::type alpha_1(alpha_1SEXP);
    Rcpp::traits::input_parameter< const double& >::type alpha_2(alpha_2SEXP);
    Rcpp::traits::input_parameter< const double& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(TN93_rate_matrix(pi_tcag, alpha_1, alpha_2, beta, xi));
    return rcpp_result_gen;
END_RCPP
}
// JC69_rate_matrix
arma::mat JC69_rate_matrix(const double& lambda, const double& xi);
RcppExport SEXP _gemino_JC69_rate_matrix(SEXP lambdaSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double& >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(JC69_rate_matrix(lambda, xi));
    return rcpp_result_gen;
END_RCPP
}
// K80_rate_matrix
arma::mat K80_rate_matrix(const double& alpha, const double& beta, const double& xi);
RcppExport SEXP _gemino_K80_rate_matrix(SEXP alphaSEXP, SEXP betaSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(K80_rate_matrix(alpha, beta, xi));
    return rcpp_result_gen;
END_RCPP
}
// F81_rate_matrix
arma::mat F81_rate_matrix(const std::vector<double>& pi_tcag, const double& xi);
RcppExport SEXP _gemino_F81_rate_matrix(SEXP pi_tcagSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(F81_rate_matrix(pi_tcag, xi));
    return rcpp_result_gen;
END_RCPP
}
// HKY85_rate_matrix
arma::mat HKY85_rate_matrix(const std::vector<double>& pi_tcag, const double& alpha, const double& beta, const double& xi);
RcppExport SEXP _gemino_HKY85_rate_matrix(SEXP pi_tcagSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const double& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(HKY85_rate_matrix(pi_tcag, alpha, beta, xi));
    return rcpp_result_gen;
END_RCPP
}
// F84_rate_matrix
arma::mat F84_rate_matrix(const std::vector<double>& pi_tcag, const double& beta, const double& kappa, const double& xi);
RcppExport SEXP _gemino_F84_rate_matrix(SEXP pi_tcagSEXP, SEXP betaSEXP, SEXP kappaSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const double& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const double& >::type kappa(kappaSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(F84_rate_matrix(pi_tcag, beta, kappa, xi));
    return rcpp_result_gen;
END_RCPP
}
// GTR_rate_matrix
arma::mat GTR_rate_matrix(const std::vector<double>& pi_tcag, const std::vector<double>& abcdef, const double& xi);
RcppExport SEXP _gemino_GTR_rate_matrix(SEXP pi_tcagSEXP, SEXP abcdefSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type abcdef(abcdefSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(GTR_rate_matrix(pi_tcag, abcdef, xi));
    return rcpp_result_gen;
END_RCPP
}
// UNREST_rate_matrix
List UNREST_rate_matrix(arma::mat Q, const double& xi);
RcppExport SEXP _gemino_UNREST_rate_matrix(SEXP QSEXP, SEXP xiSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type Q(QSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    rcpp_result_gen = Rcpp::wrap(UNREST_rate_matrix(Q, xi));
    return rcpp_result_gen;
END_RCPP
}
// see_mutations
DataFrame see_mutations(SEXP var_set_, const uint32& var_ind);
RcppExport SEXP _gemino_see_mutations(SEXP var_set_SEXP, SEXP var_indSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    rcpp_result_gen = Rcpp::wrap(see_mutations(var_set_, var_ind));
    return rcpp_result_gen;
END_RCPP
}
// examine_mutations
List examine_mutations(SEXP var_set_, const uint32& var_ind, const uint32& seq_ind);
RcppExport SEXP _gemino_examine_mutations(SEXP var_set_SEXP, SEXP var_indSEXP, SEXP seq_indSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    rcpp_result_gen = Rcpp::wrap(examine_mutations(var_set_, var_ind, seq_ind));
    return rcpp_result_gen;
END_RCPP
}
// table_gammas
std::vector<uint32> table_gammas(const std::vector<uint32>& gamma_ends, const std::vector<uint32>& positions);
RcppExport SEXP _gemino_table_gammas(SEXP gamma_endsSEXP, SEXP positionsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type gamma_ends(gamma_endsSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type positions(positionsSEXP);
    rcpp_result_gen = Rcpp::wrap(table_gammas(gamma_ends, positions));
    return rcpp_result_gen;
END_RCPP
}
// add_substitution
void add_substitution(SEXP var_set_, const uint32& var_ind, const uint32& seq_ind, const char& nucleo_, const uint32& new_pos_);
RcppExport SEXP _gemino_add_substitution(SEXP var_set_SEXP, SEXP var_indSEXP, SEXP seq_indSEXP, SEXP nucleo_SEXP, SEXP new_pos_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    Rcpp::traits::input_parameter< const char& >::type nucleo_(nucleo_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type new_pos_(new_pos_SEXP);
    add_substitution(var_set_, var_ind, seq_ind, nucleo_, new_pos_);
    return R_NilValue;
END_RCPP
}
// add_insertion
void add_insertion(SEXP var_set_, const uint32& var_ind, const uint32& seq_ind, const std::string& nucleos_, const uint32& new_pos_);
RcppExport SEXP _gemino_add_insertion(SEXP var_set_SEXP, SEXP var_indSEXP, SEXP seq_indSEXP, SEXP nucleos_SEXP, SEXP new_pos_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type nucleos_(nucleos_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type new_pos_(new_pos_SEXP);
    add_insertion(var_set_, var_ind, seq_ind, nucleos_, new_pos_);
    return R_NilValue;
END_RCPP
}
// add_deletion
void add_deletion(SEXP var_set_, const uint32& var_ind, const uint32& seq_ind, const uint32& size_, const uint32& new_pos_);
RcppExport SEXP _gemino_add_deletion(SEXP var_set_SEXP, SEXP var_indSEXP, SEXP seq_indSEXP, SEXP size_SEXP, SEXP new_pos_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type size_(size_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type new_pos_(new_pos_SEXP);
    add_deletion(var_set_, var_ind, seq_ind, size_, new_pos_);
    return R_NilValue;
END_RCPP
}
// test_rate
double test_rate(const uint32& start, const uint32& end, const uint32& var_ind, const uint32& seq_ind, SEXP var_set_, SEXP sampler_, const arma::mat& gamma_mat_);
RcppExport SEXP _gemino_test_rate(SEXP startSEXP, SEXP endSEXP, SEXP var_indSEXP, SEXP seq_indSEXP, SEXP var_set_SEXP, SEXP sampler_SEXP, SEXP gamma_mat_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type start(startSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type end(endSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< SEXP >::type sampler_(sampler_SEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type gamma_mat_(gamma_mat_SEXP);
    rcpp_result_gen = Rcpp::wrap(test_rate(start, end, var_ind, seq_ind, var_set_, sampler_, gamma_mat_));
    return rcpp_result_gen;
END_RCPP
}
// make_mutation_sampler_base
SEXP make_mutation_sampler_base(const arma::mat& Q, const double& xi, const double& psi, const std::vector<double>& pi_tcag, const arma::vec& rel_insertion_rates, const arma::vec& rel_deletion_rates);
RcppExport SEXP _gemino_make_mutation_sampler_base(SEXP QSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP pi_tcagSEXP, SEXP rel_insertion_ratesSEXP, SEXP rel_deletion_ratesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< const double& >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type rel_insertion_rates(rel_insertion_ratesSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type rel_deletion_rates(rel_deletion_ratesSEXP);
    rcpp_result_gen = Rcpp::wrap(make_mutation_sampler_base(Q, xi, psi, pi_tcag, rel_insertion_rates, rel_deletion_rates));
    return rcpp_result_gen;
END_RCPP
}
// make_mutation_sampler_chunk_base
SEXP make_mutation_sampler_chunk_base(const arma::mat& Q, const double& xi, const double& psi, const std::vector<double>& pi_tcag, const arma::vec& rel_insertion_rates, const arma::vec& rel_deletion_rates, const uint32& chunk_size);
RcppExport SEXP _gemino_make_mutation_sampler_chunk_base(SEXP QSEXP, SEXP xiSEXP, SEXP psiSEXP, SEXP pi_tcagSEXP, SEXP rel_insertion_ratesSEXP, SEXP rel_deletion_ratesSEXP, SEXP chunk_sizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Q(QSEXP);
    Rcpp::traits::input_parameter< const double& >::type xi(xiSEXP);
    Rcpp::traits::input_parameter< const double& >::type psi(psiSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pi_tcag(pi_tcagSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type rel_insertion_rates(rel_insertion_ratesSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type rel_deletion_rates(rel_deletion_ratesSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type chunk_size(chunk_sizeSEXP);
    rcpp_result_gen = Rcpp::wrap(make_mutation_sampler_chunk_base(Q, xi, psi, pi_tcag, rel_insertion_rates, rel_deletion_rates, chunk_size));
    return rcpp_result_gen;
END_RCPP
}
// print_ref_genome
void print_ref_genome(SEXP ref_genome_);
RcppExport SEXP _gemino_print_ref_genome(SEXP ref_genome_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    print_ref_genome(ref_genome_);
    return R_NilValue;
END_RCPP
}
// print_var_set
void print_var_set(SEXP var_set_);
RcppExport SEXP _gemino_print_var_set(SEXP var_set_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    print_var_set(var_set_);
    return R_NilValue;
END_RCPP
}
// see_ref_seq_size
uint32 see_ref_seq_size(SEXP ref_genome_, const uint32& s);
RcppExport SEXP _gemino_see_ref_seq_size(SEXP ref_genome_SEXP, SEXP sSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type s(sSEXP);
    rcpp_result_gen = Rcpp::wrap(see_ref_seq_size(ref_genome_, s));
    return rcpp_result_gen;
END_RCPP
}
// see_ref_n_seq
uint32 see_ref_n_seq(SEXP ref_genome_);
RcppExport SEXP _gemino_see_ref_n_seq(SEXP ref_genome_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    rcpp_result_gen = Rcpp::wrap(see_ref_n_seq(ref_genome_));
    return rcpp_result_gen;
END_RCPP
}
// optim_prob
double optim_prob(NumericVector v, NumericVector mean_pws_, NumericVector dens_, double seg_div_);
RcppExport SEXP _gemino_optim_prob(SEXP vSEXP, SEXP mean_pws_SEXP, SEXP dens_SEXP, SEXP seg_div_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type mean_pws_(mean_pws_SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dens_(dens_SEXP);
    Rcpp::traits::input_parameter< double >::type seg_div_(seg_div_SEXP);
    rcpp_result_gen = Rcpp::wrap(optim_prob(v, mean_pws_, dens_, seg_div_));
    return rcpp_result_gen;
END_RCPP
}
// sample_seqs
std::vector<uint32> sample_seqs(const uint32& total_mutations, const std::vector<double>& seq_lens, const uint32& n_cores);
RcppExport SEXP _gemino_sample_seqs(SEXP total_mutationsSEXP, SEXP seq_lensSEXP, SEXP n_coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type total_mutations(total_mutationsSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type seq_lens(seq_lensSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    rcpp_result_gen = Rcpp::wrap(sample_seqs(total_mutations, seq_lens, n_cores));
    return rcpp_result_gen;
END_RCPP
}
// cpp_nt_freq
List cpp_nt_freq(int N);
RcppExport SEXP _gemino_cpp_nt_freq(SEXP NSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_nt_freq(N));
    return rcpp_result_gen;
END_RCPP
}
// make_variants_
SEXP make_variants_(const std::vector<uint32>& n_mutations, const SEXP& ref_genome_, const std::vector<std::vector<uint32>>& snp_combo_list, const std::vector<double>& mutation_probs, const std::vector<uint32>& mutation_types, const std::vector<uint32>& mutation_sizes, const uint32& n_cores, double n2N, double alpha);
RcppExport SEXP _gemino_make_variants_(SEXP n_mutationsSEXP, SEXP ref_genome_SEXP, SEXP snp_combo_listSEXP, SEXP mutation_probsSEXP, SEXP mutation_typesSEXP, SEXP mutation_sizesSEXP, SEXP n_coresSEXP, SEXP n2NSEXP, SEXP alphaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type n_mutations(n_mutationsSEXP);
    Rcpp::traits::input_parameter< const SEXP& >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const std::vector<std::vector<uint32>>& >::type snp_combo_list(snp_combo_listSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type mutation_probs(mutation_probsSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type mutation_types(mutation_typesSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type mutation_sizes(mutation_sizesSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    Rcpp::traits::input_parameter< double >::type n2N(n2NSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    rcpp_result_gen = Rcpp::wrap(make_variants_(n_mutations, ref_genome_, snp_combo_list, mutation_probs, mutation_types, mutation_sizes, n_cores, n2N, alpha));
    return rcpp_result_gen;
END_RCPP
}
// read_ms_output_
std::vector<std::vector<std::string>> read_ms_output_(std::string ms_file);
RcppExport SEXP _gemino_read_ms_output_(SEXP ms_fileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type ms_file(ms_fileSEXP);
    rcpp_result_gen = Rcpp::wrap(read_ms_output_(ms_file));
    return rcpp_result_gen;
END_RCPP
}
// read_fasta_noind
SEXP read_fasta_noind(const std::string& fasta_file, const bool& cut_names, const bool& remove_soft_mask);
RcppExport SEXP _gemino_read_fasta_noind(SEXP fasta_fileSEXP, SEXP cut_namesSEXP, SEXP remove_soft_maskSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fasta_file(fasta_fileSEXP);
    Rcpp::traits::input_parameter< const bool& >::type cut_names(cut_namesSEXP);
    Rcpp::traits::input_parameter< const bool& >::type remove_soft_mask(remove_soft_maskSEXP);
    rcpp_result_gen = Rcpp::wrap(read_fasta_noind(fasta_file, cut_names, remove_soft_mask));
    return rcpp_result_gen;
END_RCPP
}
// read_fasta_ind
SEXP read_fasta_ind(const std::string& fasta_file, const std::string& fai_file, const bool& remove_soft_mask);
RcppExport SEXP _gemino_read_fasta_ind(SEXP fasta_fileSEXP, SEXP fai_fileSEXP, SEXP remove_soft_maskSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type fasta_file(fasta_fileSEXP);
    Rcpp::traits::input_parameter< const std::string& >::type fai_file(fai_fileSEXP);
    Rcpp::traits::input_parameter< const bool& >::type remove_soft_mask(remove_soft_maskSEXP);
    rcpp_result_gen = Rcpp::wrap(read_fasta_ind(fasta_file, fai_file, remove_soft_mask));
    return rcpp_result_gen;
END_RCPP
}
// write_fasta_fa
void write_fasta_fa(std::string file_name, SEXP ref_, const uint32& text_width);
RcppExport SEXP _gemino_write_fasta_fa(SEXP file_nameSEXP, SEXP ref_SEXP, SEXP text_widthSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type file_name(file_nameSEXP);
    Rcpp::traits::input_parameter< SEXP >::type ref_(ref_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type text_width(text_widthSEXP);
    write_fasta_fa(file_name, ref_, text_width);
    return R_NilValue;
END_RCPP
}
// write_fasta_gz
void write_fasta_gz(const std::string& file_name, SEXP ref_, const uint32& text_width);
RcppExport SEXP _gemino_write_fasta_gz(SEXP file_nameSEXP, SEXP ref_SEXP, SEXP text_widthSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type file_name(file_nameSEXP);
    Rcpp::traits::input_parameter< SEXP >::type ref_(ref_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type text_width(text_widthSEXP);
    write_fasta_gz(file_name, ref_, text_width);
    return R_NilValue;
END_RCPP
}
// see_ref_genome_seq_sizes
std::vector<uint32> see_ref_genome_seq_sizes(SEXP ref_genome_);
RcppExport SEXP _gemino_see_ref_genome_seq_sizes(SEXP ref_genome_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    rcpp_result_gen = Rcpp::wrap(see_ref_genome_seq_sizes(ref_genome_));
    return rcpp_result_gen;
END_RCPP
}
// remove_ref_genome_seq_sizes
void remove_ref_genome_seq_sizes(SEXP ref_genome_, std::vector<uint32> seq_inds);
RcppExport SEXP _gemino_remove_ref_genome_seq_sizes(SEXP ref_genome_SEXP, SEXP seq_indsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< std::vector<uint32> >::type seq_inds(seq_indsSEXP);
    remove_ref_genome_seq_sizes(ref_genome_, seq_inds);
    return R_NilValue;
END_RCPP
}
// see_ref_genome_seq_names
std::vector<std::string> see_ref_genome_seq_names(SEXP ref_genome_);
RcppExport SEXP _gemino_see_ref_genome_seq_names(SEXP ref_genome_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    rcpp_result_gen = Rcpp::wrap(see_ref_genome_seq_names(ref_genome_));
    return rcpp_result_gen;
END_RCPP
}
// set_ref_genome_seq_names
void set_ref_genome_seq_names(SEXP ref_genome_, const std::vector<uint32>& seq_inds, const std::vector<std::string>& names);
RcppExport SEXP _gemino_set_ref_genome_seq_names(SEXP ref_genome_SEXP, SEXP seq_indsSEXP, SEXP namesSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type seq_inds(seq_indsSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type names(namesSEXP);
    set_ref_genome_seq_names(ref_genome_, seq_inds, names);
    return R_NilValue;
END_RCPP
}
// see_ref_genome_seq
std::string see_ref_genome_seq(SEXP ref_genome_, const uint32& seq_ind);
RcppExport SEXP _gemino_see_ref_genome_seq(SEXP ref_genome_SEXP, SEXP seq_indSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type seq_ind(seq_indSEXP);
    rcpp_result_gen = Rcpp::wrap(see_ref_genome_seq(ref_genome_, seq_ind));
    return rcpp_result_gen;
END_RCPP
}
// make_ref_genome
SEXP make_ref_genome(const std::deque<std::string>& seqs);
RcppExport SEXP _gemino_make_ref_genome(SEXP seqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::deque<std::string>& >::type seqs(seqsSEXP);
    rcpp_result_gen = Rcpp::wrap(make_ref_genome(seqs));
    return rcpp_result_gen;
END_RCPP
}
// make_var_set
SEXP make_var_set(SEXP ref_genome_, const uint32& n_vars);
RcppExport SEXP _gemino_make_var_set(SEXP ref_genome_SEXP, SEXP n_varsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type ref_genome_(ref_genome_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_vars(n_varsSEXP);
    rcpp_result_gen = Rcpp::wrap(make_var_set(ref_genome_, n_vars));
    return rcpp_result_gen;
END_RCPP
}
// see_var_genome
std::vector<std::string> see_var_genome(SEXP var_set_, const uint32& var_ind);
RcppExport SEXP _gemino_see_var_genome(SEXP var_set_SEXP, SEXP var_indSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    rcpp_result_gen = Rcpp::wrap(see_var_genome(var_set_, var_ind));
    return rcpp_result_gen;
END_RCPP
}
// see_sizes
std::vector<uint32> see_sizes(SEXP var_set_, const uint32& var_ind);
RcppExport SEXP _gemino_see_sizes(SEXP var_set_SEXP, SEXP var_indSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type var_set_(var_set_SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type var_ind(var_indSEXP);
    rcpp_result_gen = Rcpp::wrap(see_sizes(var_set_, var_ind));
    return rcpp_result_gen;
END_RCPP
}
// test_vitter_d
arma::Mat<uint32> test_vitter_d(const uint32 reps, uint32 n, uint32 N, const uint32& n_cores, const double& n2N, const double& alpha);
RcppExport SEXP _gemino_test_vitter_d(SEXP repsSEXP, SEXP nSEXP, SEXP NSEXP, SEXP n_coresSEXP, SEXP n2NSEXP, SEXP alphaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32 >::type reps(repsSEXP);
    Rcpp::traits::input_parameter< uint32 >::type n(nSEXP);
    Rcpp::traits::input_parameter< uint32 >::type N(NSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    Rcpp::traits::input_parameter< const double& >::type n2N(n2NSEXP);
    Rcpp::traits::input_parameter< const double& >::type alpha(alphaSEXP);
    rcpp_result_gen = Rcpp::wrap(test_vitter_d(reps, n, N, n_cores, n2N, alpha));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_gemino_merge_sequences", (DL_FUNC) &_gemino_merge_sequences, 1},
    {"_gemino_filter_sequences", (DL_FUNC) &_gemino_filter_sequences, 3},
    {"_gemino_create_genome_", (DL_FUNC) &_gemino_create_genome_, 5},
    {"_gemino_rando_seqs", (DL_FUNC) &_gemino_rando_seqs, 5},
    {"_gemino_get_precleavage_lens", (DL_FUNC) &_gemino_get_precleavage_lens, 1},
    {"_gemino_expand_seqs", (DL_FUNC) &_gemino_expand_seqs, 1},
    {"_gemino_digest_var_set", (DL_FUNC) &_gemino_digest_var_set, 5},
    {"_gemino_digest_ref", (DL_FUNC) &_gemino_digest_ref, 5},
    {"_gemino_phylo_info_to_trees", (DL_FUNC) &_gemino_phylo_info_to_trees, 1},
    {"_gemino_phylo_info_to_trees_chunk", (DL_FUNC) &_gemino_phylo_info_to_trees_chunk, 1},
    {"_gemino_evolve_seqs", (DL_FUNC) &_gemino_evolve_seqs, 6},
    {"_gemino_evolve_seqs_chunk", (DL_FUNC) &_gemino_evolve_seqs_chunk, 6},
    {"_gemino_TN93_rate_matrix", (DL_FUNC) &_gemino_TN93_rate_matrix, 5},
    {"_gemino_JC69_rate_matrix", (DL_FUNC) &_gemino_JC69_rate_matrix, 2},
    {"_gemino_K80_rate_matrix", (DL_FUNC) &_gemino_K80_rate_matrix, 3},
    {"_gemino_F81_rate_matrix", (DL_FUNC) &_gemino_F81_rate_matrix, 2},
    {"_gemino_HKY85_rate_matrix", (DL_FUNC) &_gemino_HKY85_rate_matrix, 4},
    {"_gemino_F84_rate_matrix", (DL_FUNC) &_gemino_F84_rate_matrix, 4},
    {"_gemino_GTR_rate_matrix", (DL_FUNC) &_gemino_GTR_rate_matrix, 3},
    {"_gemino_UNREST_rate_matrix", (DL_FUNC) &_gemino_UNREST_rate_matrix, 2},
    {"_gemino_see_mutations", (DL_FUNC) &_gemino_see_mutations, 2},
    {"_gemino_examine_mutations", (DL_FUNC) &_gemino_examine_mutations, 3},
    {"_gemino_table_gammas", (DL_FUNC) &_gemino_table_gammas, 2},
    {"_gemino_add_substitution", (DL_FUNC) &_gemino_add_substitution, 5},
    {"_gemino_add_insertion", (DL_FUNC) &_gemino_add_insertion, 5},
    {"_gemino_add_deletion", (DL_FUNC) &_gemino_add_deletion, 5},
    {"_gemino_test_rate", (DL_FUNC) &_gemino_test_rate, 7},
    {"_gemino_make_mutation_sampler_base", (DL_FUNC) &_gemino_make_mutation_sampler_base, 6},
    {"_gemino_make_mutation_sampler_chunk_base", (DL_FUNC) &_gemino_make_mutation_sampler_chunk_base, 7},
    {"_gemino_print_ref_genome", (DL_FUNC) &_gemino_print_ref_genome, 1},
    {"_gemino_print_var_set", (DL_FUNC) &_gemino_print_var_set, 1},
    {"_gemino_see_ref_seq_size", (DL_FUNC) &_gemino_see_ref_seq_size, 2},
    {"_gemino_see_ref_n_seq", (DL_FUNC) &_gemino_see_ref_n_seq, 1},
    {"_gemino_optim_prob", (DL_FUNC) &_gemino_optim_prob, 4},
    {"_gemino_sample_seqs", (DL_FUNC) &_gemino_sample_seqs, 3},
    {"_gemino_cpp_nt_freq", (DL_FUNC) &_gemino_cpp_nt_freq, 1},
    {"_gemino_make_variants_", (DL_FUNC) &_gemino_make_variants_, 9},
    {"_gemino_read_ms_output_", (DL_FUNC) &_gemino_read_ms_output_, 1},
    {"_gemino_read_fasta_noind", (DL_FUNC) &_gemino_read_fasta_noind, 3},
    {"_gemino_read_fasta_ind", (DL_FUNC) &_gemino_read_fasta_ind, 3},
    {"_gemino_write_fasta_fa", (DL_FUNC) &_gemino_write_fasta_fa, 3},
    {"_gemino_write_fasta_gz", (DL_FUNC) &_gemino_write_fasta_gz, 3},
    {"_gemino_see_ref_genome_seq_sizes", (DL_FUNC) &_gemino_see_ref_genome_seq_sizes, 1},
    {"_gemino_remove_ref_genome_seq_sizes", (DL_FUNC) &_gemino_remove_ref_genome_seq_sizes, 2},
    {"_gemino_see_ref_genome_seq_names", (DL_FUNC) &_gemino_see_ref_genome_seq_names, 1},
    {"_gemino_set_ref_genome_seq_names", (DL_FUNC) &_gemino_set_ref_genome_seq_names, 3},
    {"_gemino_see_ref_genome_seq", (DL_FUNC) &_gemino_see_ref_genome_seq, 2},
    {"_gemino_make_ref_genome", (DL_FUNC) &_gemino_make_ref_genome, 1},
    {"_gemino_make_var_set", (DL_FUNC) &_gemino_make_var_set, 2},
    {"_gemino_see_var_genome", (DL_FUNC) &_gemino_see_var_genome, 2},
    {"_gemino_see_sizes", (DL_FUNC) &_gemino_see_sizes, 2},
    {"_gemino_test_vitter_d", (DL_FUNC) &_gemino_test_vitter_d, 6},
    {NULL, NULL, 0}
};

RcppExport void R_init_gemino(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
