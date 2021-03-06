% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/data.R
\docType{data}
\name{evo_rates}
\alias{evo_rates}
\title{Table of evolutionary rates.}
\format{A data frame with 15 rows and 8 variables:
\describe{
\item{\code{domain}}{Either \code{Bacteria} or \code{Eukarya} for what type of organism
the species is.}
\item{\code{species}}{Species name.}
\item{\code{Ge}}{Effective genome size using only coding DNA.}
\item{\code{Gc_Gnc}}{Effective genome size using coding DNA and non-coding DNA that is
under purifying selection.}
\item{\code{indels}}{Rate of insertions and deletions (\eqn{10^{-10}}{10^-10}
events per site per generation).}
\item{\code{subs}}{Base-substitution mutation rate (\eqn{10^{-10}}{10^-10}
events per site per generation).}
\item{\code{Ne}}{Effective population size (\eqn{\times 10^{6}}{* 10^6}).}
\item{\code{theta_s}}{Population mutation rate estimated using \eqn{\theta_s}{theta_s}.}
\item{\code{pi_s}}{Population mutation rate estimated using \eqn{\pi_s}{pi_s}.}
}}
\source{
\url{http://dx.doi.org/10.1534/g3.116.030890}
}
\usage{
evo_rates
}
\description{
From Table 1 in Sung et al. (2016).
}
\references{
Sung, W., M. S. Ackerman, M. M. Dillon, T. G. Platt, C. Fuqua, V. S. Cooper, and
M. Lynch. 2016. Evolution of the insertion-deletion mutation rate across the
tree of life. \emph{G3: Genes | Genomes | Genetics} \strong{6}:2583–2591.
}
\keyword{datasets}
