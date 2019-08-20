
/*
 ******************************************************************************
 ******************************************************************************

 Create rate matrices for multiple molecular-evolution models:
 TN93 and its special cases (JC69, K80, F81, HKY85, and F84), plus GTR and UNREST

 ******************************************************************************
 ******************************************************************************
 */



#include <RcppArmadillo.h>

#include <cmath> // exp, pow, remainder
#include "jackalope_types.h" // integer types
#include "util.h" // str_stop

using namespace Rcpp;




/*
 ======================================================================================
 ======================================================================================

 +Gamma model functions

 ======================================================================================
 ======================================================================================
 */



//' Incomplete Gamma function
//'
//' @noRd
//'
inline double incG(const double& a, const double& z) {
    return R::pgamma(z, a, 1.0, 0, 0) * R::gammafn(a);
}




//' Mean of truncated Gamma distribution
//'
//' From http://dx.doi.org/10.12988/astp.2013.310125.
//' As in that paper, b > 0 is the scale and c > 0 is the shape.
//'
//' @noRd
//'
double trunc_Gamma_mean(const double& b, const double& c,
                        const double& xl, const double& xu) {

    // Ran the following in Mathematica to find out that this part goes to
    // zero as xu goes to infinity:
    // > Limit[b^(-c + 1) Exp[-x/b] x^c, x -> Infinity, Assumptions -> c in real && b > 0]
    // So if xu is Inf, then we set this to zero:
    double k_;
    if (xu == arma::datum::inf) {
        k_ = 0;
    } else {
        k_ = std::exp(-1.0 * xu / b) * std::pow(b, 1-c) * std::pow(xu, c);
    }
    double k = c / (
        b * incG(1+c, xl/b) - b * incG(1+c, xu/b) +
            k_ -
            std::exp(-1.0 * xl / b) * std::pow(b, 1.0 - c) * std::pow(xl, c)
    );
    double z = -(b * b) * k * (- incG(1+c, xl / b) + incG(1+c, xu / b));
    return z;
}

//' Create a vector of Gamma values for a discrete Gamma distribution
//'
//' @noRd
//'
std::vector<double> discrete_gamma(const uint32& k,
                                   const double& shape) {

    if (shape <= 0 || k <= 1) return std::vector<double>(1, 1.0);

    std::vector<double> gammas;
    gammas.reserve(k);

    double scale = 1 / shape;
    double d_k = 1.0 / static_cast<double>(k);

    double p_cutoff = d_k;
    double xl = 0, xu = 0;

    for (uint32 i = 0; i < k; i++) {
        xl = xu;
        if (p_cutoff < 1) {
            xu = R::qgamma(p_cutoff, shape, scale, 1, 0);
        } else xu = arma::datum::inf;
        gammas.push_back(trunc_Gamma_mean(scale, shape, xl, xu));
        p_cutoff += d_k;
    }

    return gammas;

}


//' Info to calculate P(t) for TN93 model and its special cases
//'
//'
//' @noRd
//'
void Pt_info(std::vector<double> pi_tcag,
             const double& alpha_1,
             const double& alpha_2,
             const double& beta,
             std::vector<std::vector<double>>& U,
             std::vector<std::vector<double>>& Ui,
             std::vector<double>& L) {


    const double& pi_t(pi_tcag[0]);
    const double& pi_c(pi_tcag[1]);
    const double& pi_a(pi_tcag[2]);
    const double& pi_g(pi_tcag[3]);

    double pi_y = pi_t + pi_c;
    double pi_r = pi_a + pi_g;

    U = {
        {1,     1 / pi_y,       0,              pi_c / pi_y},
        {1,     1 / pi_y,       0,              -pi_t / pi_y},
        {1,     -1 / pi_r,      pi_g / pi_r,    0},
        {1,     -1 / pi_r,      -pi_a / pi_r,   0}};

    Ui = {
        {pi_t,          pi_c,           pi_a,           pi_g},
        {pi_t * pi_r,   pi_c * pi_r,    -pi_a * pi_y,   -pi_g * pi_y},
        {0,             0,              1,              -1},
        {1,             -1,             0,              0}};

    L = {0, -beta, -(pi_r * alpha_2 + pi_y * beta), -(pi_y * alpha_1 + pi_r * beta)};

    return;
}

//' Info to calculate P(t) for GTR model
//'
//'
//' @noRd
//'
void Pt_info(const arma::mat& Q,
             std::vector<std::vector<double>>& U,
             std::vector<std::vector<double>>& Ui,
             std::vector<double>& L) {


    arma::cx_vec L_;
    arma::cx_mat U_;

    arma::eig_gen(L_, U_, Q);

    arma::uvec I = arma::sort_index(arma::abs(arma::real(L_)), "descend");
    L_ = L_(I);
    U_ = U_.cols(I);

    L = arma::conv_to<std::vector<double>>::from(arma::real(L_));
    arma::mat U_mat = arma::real(U_);

    arma::mat Ui_mat = U_mat.i();

    for (uint32 i = 0; i < 4; i++) {
        U.push_back(arma::conv_to<std::vector<double>>::from(U_mat.row(i)));
        Ui.push_back(arma::conv_to<std::vector<double>>::from(Ui_mat.row(i)));
    }

    return;

}














/*
 ======================================================================================
 ======================================================================================

 Substitution model functions

 ======================================================================================
 ======================================================================================
 */








//' @describeIn sub_models TN93 model.
//'
//' @param pi_tcag Vector of length 4 indicating the equilibrium distributions of
//'     T, C, A, and G respectively. Values must be >= 0, and
//'     they are forced to sum to 1.
//' @param alpha_1 Substitution rate for T <-> C transition.
//' @param alpha_2 Substitution rate for A <-> G transition.
//' @param beta Substitution rate for transversions.
//' @param gamma_shape Numeric shape parameter for discrete Gamma distribution used for
//'     among-site variability. Values must be greater than zero.
//'     If this parameter is `NA`, among-site variability is not included.
//'     Defaults to `NA`.
//' @param gamma_k The number of categories to split the discrete Gamma distribution
//'     into. Values must be an integer in the range `[1,255]`.
//'     This argument is ignored if `gamma_shape` is `NA`.
//'     Defaults to `5`.
//' @param invariant Proportion of sites that are invariant.
//'     Values must be in the range `[0,1)`.
//'     Defaults to `0`.
//'
//' @noRd
//'
//[[Rcpp::export]]
List sub_TN93_cpp(std::vector<double> pi_tcag,
                  const double& alpha_1,
                  const double& alpha_2,
                  const double& beta,
                  const double& gamma_shape,
                  const uint32& gamma_k,
                  const double& invariant) {

    // Standardize pi_tcag first:
    double pi_sum = std::accumulate(pi_tcag.begin(), pi_tcag.end(), 0.0);
    for (double& d : pi_tcag) d /= pi_sum;

    arma::mat Q(4,4);
    Q.fill(beta);
    Q.submat(arma::span(0,1), arma::span(0,1)).fill(alpha_1);
    Q.submat(arma::span(2,3), arma::span(2,3)).fill(alpha_2);
    for (uint64 i = 0; i < 4; i++) Q.col(i) *= pi_tcag[i];

    // Reset diagonals to zero
    Q.diag().fill(0.0);
    // Filling in diagonals
    arma::vec rowsums = arma::sum(Q, 1);
    rowsums *= -1;
    Q.diag() = rowsums;

    // Extract info for P(t)
    std::vector<std::vector<double>> U;
    std::vector<std::vector<double>> Ui;
    std::vector<double> L;
    Pt_info(pi_tcag, alpha_1, alpha_2, beta, U, Ui, L);


    // Now getting vector of Gammas (which is the vector { 1 } if gamma_shape is <= 0)
    std::vector<double> gammas = discrete_gamma(gamma_k, gamma_shape);


    List out = List::create(_["Q"] = Q,
                            _["pi_tcag"] = pi_tcag,
                            _["U"] = U,
                            _["Ui"] = Ui,
                            _["L"] = L,
                            _["gammas"] = gammas,
                            _["invariant"] = invariant,
                            _["model"] = "TN93");


    return out;
}




//' @describeIn sub_models GTR model.
//'
//' @inheritParams sub_TN93
//' @param abcdef A vector of length 6 that contains the off-diagonal elements
//'     for the substitution rate matrix.
//'     See `vignette("sub-models")` for how the values are ordered in the matrix.
//'
//' @noRd
//'
//[[Rcpp::export]]
List sub_GTR_cpp(std::vector<double> pi_tcag,
                 const std::vector<double>& abcdef,
                 const double& gamma_shape,
                 const uint32& gamma_k,
                 const double& invariant) {

    // Standardize pi_tcag first:
    double pi_sum = std::accumulate(pi_tcag.begin(), pi_tcag.end(), 0.0);
    for (double& d : pi_tcag) d /= pi_sum;

    arma::mat Q(4, 4, arma::fill::zeros);

    // Filling in non-diagonals
    uint64 k = 0;
    for (uint64 i = 0; i < 3; i++) {
        for (uint64 j = i+1; j < 4; j++) {
            Q(i,j) = abcdef[k];
            Q(j,i) = abcdef[k];
            k++;
        }
    }
    for (uint64 i = 0; i < 4; i++) Q.col(i) *= pi_tcag[i];

    // Filling in diagonals
    arma::vec rowsums = arma::sum(Q, 1);
    rowsums *= -1;
    Q.diag() = rowsums;

    // Extract info for P(t)
    std::vector<std::vector<double>> U;
    std::vector<std::vector<double>> Ui;
    std::vector<double> L;
    Pt_info(Q, U, Ui, L);

    // Now getting vector of Gammas (which is the vector { 1 } if gamma_shape is <= 0)
    std::vector<double> gammas = discrete_gamma(gamma_k, gamma_shape);

    List out = List::create(_["Q"] = Q,
                            _["pi_tcag"] = pi_tcag,
                            _["U"] = U,
                            _["Ui"] = Ui,
                            _["L"] = L,
                            _["gammas"] = gammas,
                            _["invariant"] = invariant,
                            _["model"] = "GTR");

    return out;

}




//' @describeIn sub_models UNREST model.
//'
//'
//' @param Q Matrix of substitution rates for "T", "C", "A", and "G", respectively.
//'     Item `Q[i,j]` is the rate of substitution from nucleotide `i` to nucleotide `j`.
//'     Do not include indel rates here!
//'     Values on the diagonal are calculated inside the function so are ignored.
//' @inheritParams sub_TN93
//'
//' @noRd
//'
//'
//[[Rcpp::export]]
List sub_UNREST_cpp(arma::mat Q,
                    const double& gamma_shape,
                    const uint32& gamma_k,
                    const double& invariant) {

    /*
     This function also fills in a vector of equilibrium frequencies for each nucleotide.
     This calculation has to be done for this model only because it uses separate
     values for each non-diagonal cell and doesn't use equilibrium frequencies for
     creating the matrix.
     It does this by solving for πQ = 0 by finding the left eigenvector of Q that
     corresponds to the eigenvalue closest to zero.
     */

    /*
     Standardize `Q` matrix
     */
    // Make sure diagonals are set to zero so summing by row works
    Q.diag().fill(0.0);
    // Filling in diagonals
    arma::vec rowsums = arma::sum(Q, 1);
    rowsums *= -1;
    Q.diag() = rowsums;

    /*
     Estimate pi_tcag:
     */
    std::vector<double> pi_tcag(4);
    arma::cx_vec eigvals;
    arma::cx_mat eigvecs;

    arma::eig_gen(eigvals, eigvecs, Q.t());

    arma::vec vals = arma::abs(arma::real(eigvals));
    arma::mat vecs = arma::real(eigvecs);

    uint64 i = arma::as_scalar(arma::find(vals == arma::min(vals), 1));

    arma::vec left_vec = vecs.col(i);
    double sumlv = arma::accu(left_vec);

    for (uint64 i = 0; i < 4; i++) pi_tcag[i] = left_vec(i) / sumlv;


    // Info for P(t) is empty for UNREST model, since it requires matrix squaring
    std::vector<std::vector<double>> U;
    std::vector<std::vector<double>> Ui;
    std::vector<double> L;

    // Now getting vector of Gammas (which is the vector { 1 } if gamma_shape is <= 0)
    std::vector<double> gammas = discrete_gamma(gamma_k, gamma_shape);

    List out = List::create(_["Q"] = Q,
                            _["pi_tcag"] = pi_tcag,
                            _["U"] = U,
                            _["Ui"] = Ui,
                            _["L"] = L,
                            _["gammas"] = gammas,
                            _["invariant"] = invariant,
                            _["model"] = "UNREST");

    return out;
}

