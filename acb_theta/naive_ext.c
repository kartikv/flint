
#include "acb_theta.h"

/* Switch to acb_theta_naive_list once implemented */

void acb_theta_naive_ext(acb_ptr th, acb_srcptr z, const acb_mat_t tau,
        slong prec)
{
    slong g = acb_mat_nrows(tau);
    slong n = 1<<g;

    acb_theta_naive(th, z, tau, prec);
    acb_theta_naive_const(th+n, tau, prec);
}
