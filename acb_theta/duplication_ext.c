
#include "acb_theta.h"

void acb_theta_duplication_ext(acb_ptr th2, acb_srcptr th, slong g,
        slong prec)
{
    acb_theta_agm_ext_step_sqrt(th2, th, g, prec);
}
