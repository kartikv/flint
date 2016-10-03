/*
  Copyright (C) 2016 Elias Tsigaridas

  This file is part of FLINT.

  FLINT is free software: you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License (LGPL) as published
  by the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fmpz_poly_solve.h"

int
main(void)
{
    int iter;
    FLINT_TEST_INIT(state);

    flint_printf("sgn_eval_at_c....");
    fflush(stdout);

    /* Check aliasing */
    for (iter = 0; iter < 12; iter++)
      /* 1000 * flint_test_multiplier(); iter++) */
    {
        printf("iter: %d\n\n", iter);
        fmpz_t a;
        fmpz_poly_t f, g;
        slong i;
        int s1, s2;

        fmpz_init(a);
        fmpz_poly_init(f);
        fmpz_poly_init(g);

        
        fmpz_one(a);
        printf("AA\n");
        fmpz_poly_randtest(f, state, n_randint(state, 100), 200);
        printf("BB\n");
        /* s1 = fmpz_poly_solve_sgn_eval_at_c(f, a); */
        printf("CC\n");
        /* fmpz_poly_set(g, f); */
        /* d = fmpz_poly_degree(g); */
        /* for (i = 0; i <= d; i++) */
        /* { */
        /*     fmpz_mul_2exp(fmpz_poly_get_coeff_ptr(g, i), */
        /*                   fmpz_poly_get_coeff_ptr(g, i), d - i); */
        /* } */


        /* fmpz_poly_evaluate_fmpz(a, g, a);

        //s2 = fmpz_sgn(a);v*/
        s2=s1;
        printf("s1 = %d, s2 = %d\n\n", s1, s2);
        if (s1 != s2)
        {

          flint_printf("FAIL:\n");
          
          fmpz_poly_print(f); printf("\n\n");
          printf("s1 = %d, s2 = %d\n\n", s1, s2);
          abort();
        }


        fmpz_clear(a);
        fmpz_poly_clear(f);
        fmpz_poly_clear(g);
    }

    FLINT_TEST_CLEANUP(state);
    flint_printf("PASS\n");
    return 0;
}