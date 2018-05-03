#ifndef __GEMINO_RATE_MATRICES_H
#define __GEMINO_RATE_MATRICES_H



/*
 ******************************************************************************
 ******************************************************************************

 Create rate matrices for multiple molecular-evolution models:
 TN93 and its special cases (JC69, K80, F81, HKY85, and F84), plus GTR and UNREST

 ******************************************************************************
 ******************************************************************************
 */



#include <RcppArmadillo.h>

#include "gemino_types.h" // integer types

using namespace Rcpp;


inline arma::mat TN93_rate_matrix(const double& pi_t, const double& pi_c,
                                  const double& pi_a, const double& pi_g,
                                  const double& alpha_1, const double& alpha_2,
                                  const double& beta, const double& xi);

inline arma::mat JC69_rate_matrix(const double& lambda, const double& xi);

inline arma::mat K80_rate_matrix(const double& alpha, const double& beta,
                                 const double& xi);

inline arma::mat F81_rate_matrix(const double& pi_t, const double& pi_c,
                                 const double& pi_a, const double& pi_g,
                                 const double& xi);

inline arma::mat HKY85_rate_matrix(const double& pi_t, const double& pi_c,
                                   const double& pi_a, const double& pi_g,
                                   const double& alpha, const double& beta,
                                   const double& xi);

inline arma::mat F84_rate_matrix(const double& pi_t, const double& pi_c,
                                 const double& pi_a, const double& pi_g,
                                 const double& beta, const double& kappa,
                                 const double& xi);

inline arma::mat GTR_rate_matrix(const double& pi_t, const double& pi_c,
                                 const double& pi_a, const double& pi_g,
                                 const double& a, const double& b, const double& c,
                                 const double& d, const double& e, const double& f,
                                 const double& xi);

inline arma::mat UNREST_rate_matrix(arma::mat Q, const double& xi);



#endif