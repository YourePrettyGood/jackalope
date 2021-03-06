
<!-- README.md is generated from README.Rmd. Please edit that file -->

[![Project Status: Active – The project has reached a stable, usable
state and is being actively
developed.](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![Build
Status](https://travis-ci.com/lucasnell/jackalope.svg?branch=master)](https://travis-ci.com/lucasnell/jackalope)
[![codecov](https://codecov.io/gh/lucasnell/jackalope/branch/master/graph/badge.svg)](https://codecov.io/gh/lucasnell/jackalope)
[![AppVeyor build
status](https://ci.appveyor.com/api/projects/status/github/lucasnell/jackalope?branch=master&svg=true)](https://ci.appveyor.com/project/lucasnell/jackalope)
[![CRAN\_Status\_Badge](http://www.r-pkg.org/badges/version/jackalope)](https://cran.r-project.org/package=jackalope)

# jackalope <img src="man/figures/logo.png" align="right" alt="" width="120" />

## Overview

For studies using high-throughput sequencing (HTS) data, simulations can
be vital for planning sampling design and testing bioinformatic tools.
However, most HTS sequencing tools provide only very simple ways of
adding deviations from a reference genome. For HTS studies that focus on
patterns of genomic variation among individuals, populations, or
species, having a tool that can simulate realistic patterns of molecular
evolution and generate HTS data from those simulations would be quite
useful.

`jackalope` simply and efficiently simulates (i) variants from reference
genomes and (ii) reads from both Illumina and Pacific Biosciences
(PacBio) platforms. It can either read reference genomes from FASTA
files or simulate new ones. Genomic variants can be simulated using
summary statistics, phylogenies, Variant Call Format (VCF) files, and
coalescent simulations—the latter of which can include selection,
recombination, and demographic fluctuations. `jackalope` can simulate
single, paired-end, or mate-pair Illumina reads, as well as reads from
Pacific Biosciences These simulations include sequencing errors, mapping
qualities, multiplexing, and optical/PCR duplicates. All outputs can be
written to standard file formats.

## Installation

### Dependencies

Before installing `jackalope`, you should update the packages `Rhtslib`
and `zlibbioc`. Since both of these are on Bioconductor, you should
update `BiocManager`, too.

``` r
if (!requireNamespace("BiocManager", quietly = TRUE) ||
    "BiocManager" %in% row.names(old.packages())) {
  install.packages("BiocManager")
}
BiocManager::install(c("Rhtslib", "zlibbioc"))
```

### Stable version

``` r
# To install the latest stable version from CRAN:
install.packages("jackalope")
```

### Development version

``` r
# install.packages("devtools")
devtools::install_github("lucasnell/jackalope")
```

### Enabling OpenMP

To use multithreading in `jackalope`, you’ll need to compile it from
source using the proper flags. The first step is to add the following to
the `.R/Makevars` (`.R/Makevars.win` on Windows) file inside the home
directory:

``` bash
PKG_CXXFLAGS += $(SHLIB_OPENMP_CXXFLAGS)
PKG_CFLAGS += $(SHLIB_OPENMP_CFLAGS)
PKG_LIBS += $(SHLIB_OPENMP_CFLAGS)
```

On Linux and Windows, you should be able to get away with simply adding
those lines and installing `jackalope` by running the following in R:

``` r
install.packages("jackalope", type = "source")
## Or, for development version:
# devtools::install_github("lucasnell/jackalope")
```

If you’ve enabled OpenMP properly, running `jackalope:::using_openmp()`
in R should return `TRUE`.

On macOS, it takes a few more steps to get things working. First, make
sure the content above is in your `~/.R/Makevars` file. Next, go to
<https://cran.r-project.org/bin/macosx/tools> and download the newest
versions of (1) the `clang` compiler (version 8 at the time of writing)
and (2) GNU Fortran (version 6.1 at the time of writing). The downloads
will have the `.pkg` extension. Next, install `clang` and `gfortran` by
opening these `.pkg` files and following the directions.

After this, add the following to your `~/.R/Makevars` file (replacing
`clang8` with your version of the clang compiler):

``` bash
CLANG8=/usr/local/clang8/bin/clang
CC=$(CLANG8)
CXX=$(CLANG8)++
CXX11=$(CLANG8)++
CXX14=$(CLANG8)++
CXX17=$(CLANG8)++
CXX1X=$(CLANG8)++
LDFLAGS=-L/usr/local/clang8/lib
```

Now you should be able to install `jackalope` by running
`install.packages("jackalope", type = "source")` in R.

For more information, please see
<https://thecoatlessprofessor.com/programming/openmp-in-r-on-os-x>.

## Usage

Below shows how to simulate a 10kb genome, then create variants from
that genome using a phylogenetic tree:

``` r
library(jackalope)
reference <- create_genome(n_chroms = 10, len_mean = 1000)
tr <- ape::rcoal(5)
ref_variants <- create_variants(reference, vars_phylo(tr), sub_JC69(0.1))
ref_variants
#>                               << Variants object >>
#> # Variants: 5
#> # Mutations: 16,870
#> 
#>                           << Reference genome info: >>
#> < Set of 10 chromosomes >
#> # Total size: 10,000 bp
#>   name                             chromosome                             length
#> chrom0     CTGGCATTGAATCATATGAGGTGGCCAT...ACGTTGCACGATTGATTAAATTCCTGAA      1000
#> chrom1     CACTCCGTCGCACACTAGGTTTCGAGAT...GTGAGCTCGCGTACATGGAGCATTCTGT      1000
#> chrom2     CTTAGCCGGAGCGACTCGGAGCAACTGC...TGGCGTAATATGCCAGGTCCCGCGTGGC      1000
#> chrom3     CGCCTTCCATTTAGGACTTGTATTGGTG...GCTAAACTCCATGTGACTGTAATGTCAG      1000
#> chrom4     GGGTGATATGGTGTGCATGCTGAATTCG...AGAGTCTAGAGTCTCTGGGAGGTCAGGT      1000
#> chrom5     TTCGTTGGTGGGTGTCCTATGCTACGAT...CGCCCGCCGGTTTGACTTACTCGATTGG      1000
#> chrom6     GCATGGACAGATGTGATCTGAGTATACG...CAGACCCCATAAGGCCTGGGACACTGTG      1000
#> chrom7     TCGTTTCAACGTCCTTAAGTGTAGTATC...GGCTCGTTAGCTCTCCGAGGAGACGAGG      1000
#> chrom8     CAGGTAAGTTATCAAAGAACCTTCCTGG...ACGCATCACCTCGCAAGGAGACTCGTTA      1000
#> chrom9     GGTAGTAATTAGGCTTAAAATAGCAGTG...ATAACAAATGTTCGGCATACGATCTACG      1000
```

Below simulates 500 million paired-end, 100 bp reads from the variants:

``` r
illumina(ref_variants, out_prefix = "illumina", n_reads = 500e6,
         paired = TRUE, read_length = 100)
```

Below simulates 500 thousand PacBio reads from the reference genome:

``` r
pacbio(ref, out_prefix = "pacbio", n_reads = 500e3)
```
