# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' Merge a reference genome into a single chromosome.
#'
#'
#' @param ref_genome_ptr An external pointer (R class \code{externalptr}) to a
#'     \code{RefGenome} class in C++ (the full class in C++ is
#'     \code{Rcpp::XPtr<RefGenome>}).
#'
#' @return Nothing. Changes are made in place.
#'
#' @name merge_chromosomes
#'
#' @noRd
#'
merge_chromosomes_cpp <- function(ref_genome_ptr) {
    invisible(.Call(`_jackalope_merge_chromosomes_cpp`, ref_genome_ptr))
}

#' Filter reference genome chromosomes by size or for a proportion of total nucleotides.
#'
#'
#' @inheritParams ref_genome_ptr merge_chromosomes
#' @param min_chrom_size Integer minimum chromosome size to keep.
#'     Defaults to \code{0}, which results in this argument being ignored.
#' @param out_chrom_prop Numeric proportion of total chromosome to keep.
#'     Defaults to \code{0}, which results in this argument being ignored.
#'
#' @return Nothing. Changes are made in place.
#'
#' @name filter_chromosomes
#'
#' @noRd
#'
#'
filter_chromosomes_cpp <- function(ref_genome_ptr, min_chrom_size = 0L, out_chrom_prop = 0) {
    invisible(.Call(`_jackalope_filter_chromosomes_cpp`, ref_genome_ptr, min_chrom_size, out_chrom_prop))
}

#' Replace Ns with randome nucleotides.
#'
#'
#' @return Nothing. Changes are made in place.
#'
#' @name replace_Ns_cpp
#'
#' @noRd
#'
#'
replace_Ns_cpp <- function(ref_genome_ptr, pi_tcag, n_threads, show_progress) {
    invisible(.Call(`_jackalope_replace_Ns_cpp`, ref_genome_ptr, pi_tcag, n_threads, show_progress))
}

#' Create `RefGenome` pointer based on nucleotide equilibrium frequencies.
#'
#' Function to create random chromosomes for a new reference genome object.
#'
#' Note that this function will never return empty chromosomes.
#'
#' @param n_chroms Number of chromosomes.
#' @param len_mean Mean for the gamma distribution for chromosome sizes.
#' @param len_sd Standard deviation for the gamma distribution for chromosome sizes.
#'     If set to `<= 0`, all chromosomes will be the same length.
#' @param pi_tcag Vector of nucleotide equilibrium frequencies for
#'     "T", "C", "A", and "G", respectively.
#' @param n_threads Number of threads to use via OpenMP.
#'
#'
#' @return External pointer to a `RefGenome` C++ object.
#'
#' @noRd
#'
#' @examples
#'
#'
create_genome_cpp <- function(n_chroms, len_mean, len_sd, pi_tcag, n_threads) {
    .Call(`_jackalope_create_genome_cpp`, n_chroms, len_mean, len_sd, pi_tcag, n_threads)
}

#' Create random chromosomes as a character vector.
#'
#' This function is used internally for testing.
#'
#'
#' @inheritParams create_genome
#'
#' @return Character vector of chromosome strings.
#'
#'
#' @noRd
#'
rando_chroms <- function(n_chroms, len_mean, len_sd = 0, pi_tcag = numeric(0), n_threads = 1L) {
    .Call(`_jackalope_rando_chroms`, n_chroms, len_mean, len_sd, pi_tcag, n_threads)
}

#' Illumina chromosome for reference object.
#'
#'
#' @noRd
#'
illumina_ref_cpp <- function(ref_genome_ptr, paired, matepair, out_prefix, compress, comp_method, n_reads, prob_dup, n_threads, show_progress, read_pool_size, frag_len_shape, frag_len_scale, frag_len_min, frag_len_max, qual_probs1, quals1, ins_prob1, del_prob1, qual_probs2, quals2, ins_prob2, del_prob2, barcodes) {
    invisible(.Call(`_jackalope_illumina_ref_cpp`, ref_genome_ptr, paired, matepair, out_prefix, compress, comp_method, n_reads, prob_dup, n_threads, show_progress, read_pool_size, frag_len_shape, frag_len_scale, frag_len_min, frag_len_max, qual_probs1, quals1, ins_prob1, del_prob1, qual_probs2, quals2, ins_prob2, del_prob2, barcodes))
}

#' Illumina chromosome for reference object.
#'
#'
#' @noRd
#'
illumina_var_cpp <- function(var_set_ptr, paired, matepair, out_prefix, sep_files, compress, comp_method, n_reads, prob_dup, n_threads, show_progress, read_pool_size, variant_probs, frag_len_shape, frag_len_scale, frag_len_min, frag_len_max, qual_probs1, quals1, ins_prob1, del_prob1, qual_probs2, quals2, ins_prob2, del_prob2, barcodes) {
    invisible(.Call(`_jackalope_illumina_var_cpp`, var_set_ptr, paired, matepair, out_prefix, sep_files, compress, comp_method, n_reads, prob_dup, n_threads, show_progress, read_pool_size, variant_probs, frag_len_shape, frag_len_scale, frag_len_min, frag_len_max, qual_probs1, quals1, ins_prob1, del_prob1, qual_probs2, quals2, ins_prob2, del_prob2, barcodes))
}

#' PacBio chromosome for reference object.
#'
#'
#' @noRd
#'
pacbio_ref_cpp <- function(ref_genome_ptr, out_prefix, compress, comp_method, n_reads, n_threads, show_progress, read_pool_size, prob_dup, scale, sigma, loc, min_read_len, read_probs, read_lens, max_passes, chi2_params_n, chi2_params_s, sqrt_params, norm_params, prob_thresh, prob_ins, prob_del, prob_subst) {
    invisible(.Call(`_jackalope_pacbio_ref_cpp`, ref_genome_ptr, out_prefix, compress, comp_method, n_reads, n_threads, show_progress, read_pool_size, prob_dup, scale, sigma, loc, min_read_len, read_probs, read_lens, max_passes, chi2_params_n, chi2_params_s, sqrt_params, norm_params, prob_thresh, prob_ins, prob_del, prob_subst))
}

#' PacBio chromosome for reference object.
#'
#'
#' @noRd
#'
pacbio_var_cpp <- function(var_set_ptr, out_prefix, sep_files, compress, comp_method, n_reads, n_threads, show_progress, read_pool_size, variant_probs, prob_dup, scale, sigma, loc, min_read_len, read_probs, read_lens, max_passes, chi2_params_n, chi2_params_s, sqrt_params, norm_params, prob_thresh, prob_ins, prob_del, prob_subst) {
    invisible(.Call(`_jackalope_pacbio_var_cpp`, var_set_ptr, out_prefix, sep_files, compress, comp_method, n_reads, n_threads, show_progress, read_pool_size, variant_probs, prob_dup, scale, sigma, loc, min_read_len, read_probs, read_lens, max_passes, chi2_params_n, chi2_params_s, sqrt_params, norm_params, prob_thresh, prob_ins, prob_del, prob_subst))
}

#' Read a non-indexed fasta file to a \code{RefGenome} object.
#'
#' @param file_names File names of the fasta file(s).
#' @param cut_names Boolean for whether to cut chromosome names at the first space.
#'     Defaults to \code{TRUE}.
#' @param remove_soft_mask Boolean for whether to remove soft-masking by making
#'    chromosomes all uppercase. Defaults to \code{TRUE}.
#'
#' @return Nothing.
#'
#' @noRd
#'
read_fasta_noind <- function(fasta_files, cut_names, remove_soft_mask) {
    .Call(`_jackalope_read_fasta_noind`, fasta_files, cut_names, remove_soft_mask)
}

#' Read an indexed fasta file to a \code{RefGenome} object.
#'
#' @param file_name File name of the fasta file.
#' @param remove_soft_mask Boolean for whether to remove soft-masking by making
#'    chromosomes all uppercase. Defaults to \code{TRUE}.
#' @param offsets Vector of chromosome offsets from the fasta index file.
#' @param names Vector of chromosome names from the fasta index file.
#' @param lengths Vector of chromosome lengths from the fasta index file.
#' @param line_lens Vector of chromosome line lengths from the fasta index file.
#'
#' @return Nothing.
#'
#' @noRd
#'
#'
read_fasta_ind <- function(fasta_files, fai_files, remove_soft_mask) {
    .Call(`_jackalope_read_fasta_ind`, fasta_files, fai_files, remove_soft_mask)
}

#' Write \code{RefGenome} to an uncompressed fasta file.
#'
#' @param out_prefix Prefix to file name of output fasta file.
#' @param ref_genome_ptr An external pointer to a \code{RefGenome} C++ object.
#' @param text_width The number of characters per line in the output fasta file.
#' @param compress Boolean for whether to compress output.
#'
#' @return Nothing.
#'
#' @noRd
#'
#'
write_ref_fasta <- function(out_prefix, ref_genome_ptr, text_width, compress, comp_method, show_progress) {
    invisible(.Call(`_jackalope_write_ref_fasta`, out_prefix, ref_genome_ptr, text_width, compress, comp_method, show_progress))
}

#' Write \code{VarSet} to an uncompressed fasta file.
#'
#' @param out_prefix Prefix to file name of output fasta file.
#' @param var_set_ptr An external pointer to a \code{VarSet} C++ object.
#' @param text_width The number of characters per line in the output fasta file.
#' @param compress Boolean for whether to compress output.
#'
#' @return Nothing.
#'
#' @noRd
#'
#'
write_vars_fasta <- function(out_prefix, var_set_ptr, text_width, compress, comp_method, n_threads, show_progress) {
    invisible(.Call(`_jackalope_write_vars_fasta`, out_prefix, var_set_ptr, text_width, compress, comp_method, n_threads, show_progress))
}

#' Read a ms output file with newick gene trees and return the gene tree strings.
#'
#' @param ms_file File name of the ms output file.
#'
#' @return A vector of strings for each set of gene trees.
#'
#' @noRd
#'
read_ms_trees_ <- function(ms_file) {
    .Call(`_jackalope_read_ms_trees_`, ms_file)
}

#' Read a ms output file with segregating sites and return the matrices of site info.
#'
#' @param ms_file File name of the ms output file.
#'
#' @return A vector of strings for each set of gene trees.
#'
#' @noRd
#'
coal_file_sites <- function(ms_file) {
    .Call(`_jackalope_coal_file_sites`, ms_file)
}

read_vcf_cpp <- function(reference_ptr, fn, print_names) {
    .Call(`_jackalope_read_vcf_cpp`, reference_ptr, fn, print_names)
}

#' Write `variants` to VCF file.
#'
#'
#' @noRd
#'
write_vcf_cpp <- function(out_prefix, compress, var_set_ptr, sample_matrix, show_progress) {
    invisible(.Call(`_jackalope_write_vcf_cpp`, out_prefix, compress, var_set_ptr, sample_matrix, show_progress))
}

#' Evolve all chromosomes in a reference genome.
#'
#' @noRd
#'
evolve_across_trees <- function(ref_genome_ptr, genome_phylo_info, Q, U, Ui, L, invariant, insertion_rates, deletion_rates, epsilon, pi_tcag, n_threads, show_progress) {
    .Call(`_jackalope_evolve_across_trees`, ref_genome_ptr, genome_phylo_info, Q, U, Ui, L, invariant, insertion_rates, deletion_rates, epsilon, pi_tcag, n_threads, show_progress)
}

#' Add mutations manually from R.
#'
#' This section applies to the next 3 functions.
#'
#' Note that all indices are in 0-based C++ indexing. This means that the first
#' item is indexed by `0`, and so forth.
#'
#' @param var_set_ptr External pointer to a C++ `VarSet` object
#' @param var_ind Integer index to the desired variant. Uses 0-based indexing!
#' @param chrom_ind Integer index to the desired chromosome. Uses 0-based indexing!
#' @param new_pos_ Integer index to the desired subsitution location.
#'     Uses 0-based indexing!
#'
#' @noRd
NULL

#' Function to print info on a `RefGenome`.
#'
#' Access `RefGenome` class's print method from R.
#'
#' @noRd
#'
print_ref_genome <- function(ref_genome_ptr) {
    invisible(.Call(`_jackalope_print_ref_genome`, ref_genome_ptr))
}

#' Function to print info on a VarSet.
#'
#' Access `VarSet` class's print method from R.
#'
#' @noRd
#'
print_var_set <- function(var_set_ptr) {
    invisible(.Call(`_jackalope_print_var_set`, var_set_ptr))
}

#' Make a RefGenome object from a set of chromosomes.
#'
#' Used for testing.
#'
#' @noRd
#'
make_ref_genome <- function(chroms) {
    .Call(`_jackalope_make_ref_genome`, chroms)
}

#' Make a VarSet object from a RefGenome pointer and # variants.
#'
#' Used for testing.
#'
#'
#' @noRd
#'
make_var_set <- function(ref_genome_ptr, n_vars) {
    .Call(`_jackalope_make_var_set`, ref_genome_ptr, n_vars)
}

view_ref_genome_nchroms <- function(ref_genome_ptr) {
    .Call(`_jackalope_view_ref_genome_nchroms`, ref_genome_ptr)
}

view_var_set_nchroms <- function(var_set_ptr) {
    .Call(`_jackalope_view_var_set_nchroms`, var_set_ptr)
}

view_var_set_nvars <- function(var_set_ptr) {
    .Call(`_jackalope_view_var_set_nvars`, var_set_ptr)
}

view_ref_genome_chrom_sizes <- function(ref_genome_ptr) {
    .Call(`_jackalope_view_ref_genome_chrom_sizes`, ref_genome_ptr)
}

#' See all chromosome sizes in a VarGenome object within a VarSet.
#'
#' @noRd
#'
view_var_genome_chrom_sizes <- function(var_set_ptr, var_ind) {
    .Call(`_jackalope_view_var_genome_chrom_sizes`, var_set_ptr, var_ind)
}

view_ref_genome_chrom <- function(ref_genome_ptr, chrom_ind) {
    .Call(`_jackalope_view_ref_genome_chrom`, ref_genome_ptr, chrom_ind)
}

#' Function to piece together the strings for one chromosome in a VarGenome.
#'
#' @noRd
#'
view_var_genome_chrom <- function(var_set_ptr, var_ind, chrom_ind) {
    .Call(`_jackalope_view_var_genome_chrom`, var_set_ptr, var_ind, chrom_ind)
}

view_ref_genome <- function(ref_genome_ptr) {
    .Call(`_jackalope_view_ref_genome`, ref_genome_ptr)
}

#' Function to piece together the strings for all chromosomes in a VarGenome.
#'
#' @noRd
#'
view_var_genome <- function(var_set_ptr, var_ind) {
    .Call(`_jackalope_view_var_genome`, var_set_ptr, var_ind)
}

view_ref_genome_chrom_names <- function(ref_genome_ptr) {
    .Call(`_jackalope_view_ref_genome_chrom_names`, ref_genome_ptr)
}

#' See all variant-genome names in a VarSet object.
#'
#' @noRd
#'
view_var_set_var_names <- function(var_set_ptr) {
    .Call(`_jackalope_view_var_set_var_names`, var_set_ptr)
}

#' See GC content in a RefGenome object.
#'
#' @noRd
#'
view_ref_genome_gc_content <- function(ref_genome_ptr, chrom_ind, start, end) {
    .Call(`_jackalope_view_ref_genome_gc_content`, ref_genome_ptr, chrom_ind, start, end)
}

#' See GC content in a VarSet object.
#'
#' @noRd
#'
view_var_set_gc_content <- function(var_set_ptr, chrom_ind, var_ind, start, end) {
    .Call(`_jackalope_view_var_set_gc_content`, var_set_ptr, chrom_ind, var_ind, start, end)
}

#' See any nucleotide's content in a RefGenome object.
#'
#' @noRd
#'
view_ref_genome_nt_content <- function(ref_genome_ptr, nt, chrom_ind, start, end) {
    .Call(`_jackalope_view_ref_genome_nt_content`, ref_genome_ptr, nt, chrom_ind, start, end)
}

#' See any nucleotide's content in a VarSet object.
#'
#' @noRd
#'
view_var_set_nt_content <- function(var_set_ptr, nt, chrom_ind, var_ind, start, end) {
    .Call(`_jackalope_view_var_set_nt_content`, var_set_ptr, nt, chrom_ind, var_ind, start, end)
}

set_ref_genome_chrom_names <- function(ref_genome_ptr, chrom_inds, names) {
    invisible(.Call(`_jackalope_set_ref_genome_chrom_names`, ref_genome_ptr, chrom_inds, names))
}

clean_ref_genome_chrom_names <- function(ref_genome_ptr) {
    invisible(.Call(`_jackalope_clean_ref_genome_chrom_names`, ref_genome_ptr))
}

set_var_set_var_names <- function(var_set_ptr, var_inds, names) {
    invisible(.Call(`_jackalope_set_var_set_var_names`, var_set_ptr, var_inds, names))
}

remove_ref_genome_chroms <- function(ref_genome_ptr, chrom_inds) {
    invisible(.Call(`_jackalope_remove_ref_genome_chroms`, ref_genome_ptr, chrom_inds))
}

remove_var_set_vars <- function(var_set_ptr, var_inds) {
    invisible(.Call(`_jackalope_remove_var_set_vars`, var_set_ptr, var_inds))
}

add_ref_genome_chroms <- function(ref_genome_ptr, new_chroms, new_names) {
    invisible(.Call(`_jackalope_add_ref_genome_chroms`, ref_genome_ptr, new_chroms, new_names))
}

add_var_set_vars <- function(var_set_ptr, new_names) {
    invisible(.Call(`_jackalope_add_var_set_vars`, var_set_ptr, new_names))
}

dup_var_set_vars <- function(var_set_ptr, var_inds, new_names) {
    invisible(.Call(`_jackalope_dup_var_set_vars`, var_set_ptr, var_inds, new_names))
}

#' Turns a VarGenome's mutations into a list of data frames.
#'
#' Internal function for testing.
#'
#'
#' @noRd
#'
view_mutations <- function(var_set_ptr, var_ind) {
    .Call(`_jackalope_view_mutations`, var_set_ptr, var_ind)
}

#' Turns a VarGenome's mutations into a list of data frames.
#'
#' Internal function for testing.
#'
#'
#' @noRd
#'
examine_mutations <- function(var_set_ptr, var_ind, chrom_ind) {
    .Call(`_jackalope_examine_mutations`, var_set_ptr, var_ind, chrom_ind)
}

#' @describeIn add_mutations Add a substitution.
#'
#' @inheritParams add_mutations
#' @param nucleo_ Character to substitute for existing one.
#'
#' @noRd
#'
add_substitution <- function(var_set_ptr, var_ind, chrom_ind, nucleo_, new_pos_) {
    invisible(.Call(`_jackalope_add_substitution`, var_set_ptr, var_ind, chrom_ind, nucleo_, new_pos_))
}

#' @describeIn add_mutations Add an insertion.
#'
#' @inheritParams add_mutations
#' @param nucleos_ Nucleotides to insert at the desired location.
#'
#'
#' @noRd
#'
add_insertion <- function(var_set_ptr, var_ind, chrom_ind, nucleos_, new_pos_) {
    invisible(.Call(`_jackalope_add_insertion`, var_set_ptr, var_ind, chrom_ind, nucleos_, new_pos_))
}

#' @describeIn add_mutations Add a deletion.
#'
#' @inheritParams add_mutations
#' @param size_ Size of deletion.
#'
#'
#' @noRd
#'
add_deletion <- function(var_set_ptr, var_ind, chrom_ind, size_, new_pos_) {
    invisible(.Call(`_jackalope_add_deletion`, var_set_ptr, var_ind, chrom_ind, size_, new_pos_))
}

#' Incomplete Gamma function
#'
#' @noRd
#'
NULL

#' Mean of truncated Gamma distribution
#'
#' From http://dx.doi.org/10.12988/astp.2013.310125.
#' As in that paper, b > 0 is the scale and c > 0 is the shape.
#'
#' @noRd
#'
NULL

#' Create a vector of Gamma values for a discrete Gamma distribution.
#'
#'
#' @noRd
#'
NULL

#' Info to calculate P(t) for TN93 model and its special cases
#'
#'
#' @noRd
#'
NULL

#' Info to calculate P(t) for GTR model
#'
#'
#' @noRd
#'
NULL

#' @describeIn sub_models TN93 model.
#'
#' @param pi_tcag Vector of length 4 indicating the equilibrium distributions of
#'     T, C, A, and G respectively. Values must be >= 0, and
#'     they are forced to sum to 1.
#' @param alpha_1 Substitution rate for T <-> C transition.
#' @param alpha_2 Substitution rate for A <-> G transition.
#' @param beta Substitution rate for transversions.
#' @param gamma_shape Numeric shape parameter for discrete Gamma distribution used for
#'     among-site variability. Values must be greater than zero.
#'     If this parameter is `NA`, among-site variability is not included.
#'     Defaults to `NA`.
#' @param gamma_k The number of categories to split the discrete Gamma distribution
#'     into. Values must be an integer in the range `[1,255]`.
#'     This argument is ignored if `gamma_shape` is `NA`.
#'     Defaults to `5`.
#' @param invariant Proportion of sites that are invariant.
#'     Values must be in the range `[0,1)`.
#'     Defaults to `0`.
#'
#' @noRd
#'
sub_TN93_cpp <- function(pi_tcag, alpha_1, alpha_2, beta, gamma_shape, gamma_k, invariant) {
    .Call(`_jackalope_sub_TN93_cpp`, pi_tcag, alpha_1, alpha_2, beta, gamma_shape, gamma_k, invariant)
}

#' @describeIn sub_models GTR model.
#'
#' @inheritParams sub_TN93
#' @param abcdef A vector of length 6 that contains the off-diagonal elements
#'     for the substitution rate matrix.
#'     See `vignette("sub-models")` for how the values are ordered in the matrix.
#'
#' @noRd
#'
sub_GTR_cpp <- function(pi_tcag, abcdef, gamma_shape, gamma_k, invariant) {
    .Call(`_jackalope_sub_GTR_cpp`, pi_tcag, abcdef, gamma_shape, gamma_k, invariant)
}

#' @describeIn sub_models UNREST model.
#'
#'
#' @param Q Matrix of substitution rates for "T", "C", "A", and "G", respectively.
#'     Item `Q[i,j]` is the rate of substitution from nucleotide `i` to nucleotide `j`.
#'     Do not include indel rates here!
#'     Values on the diagonal are calculated inside the function so are ignored.
#' @inheritParams sub_TN93
#'
#' @noRd
#'
#'
sub_UNREST_cpp <- function(Q, gamma_shape, gamma_k, invariant) {
    .Call(`_jackalope_sub_UNREST_cpp`, Q, gamma_shape, gamma_k, invariant)
}

using_openmp <- function() {
    .Call(`_jackalope_using_openmp`)
}

#' Used below to directly make a MutationTypeSampler
#'
#' @noRd
#'
NULL

#' Add mutations at segregating sites for one chromosome from coalescent simulation output.
#'
#' @noRd
#'
NULL

#' Add mutations at segregating sites from coalescent simulation output.
#'
#' @noRd
#'
add_ssites_cpp <- function(ref_genome_ptr, seg_sites, Q, pi_tcag, insertion_rates, deletion_rates, n_threads, show_progress) {
    .Call(`_jackalope_add_ssites_cpp`, ref_genome_ptr, seg_sites, Q, pi_tcag, insertion_rates, deletion_rates, n_threads, show_progress)
}

