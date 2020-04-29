/*
    Copyright (C) 2010 Fredrik Johansson

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <gmp.h>
#include "flint.h"
#include "nmod_sparse_mat.h"
#include "ulong_extras.h"

int
main(void)
{
    slong rep, r, c;
    mp_limb_t n;
    nmod_t mod;
    nmod_sparse_mat_t A, B, C;
    FLINT_TEST_INIT(state);
    

    flint_printf("transpose....");
    fflush(stdout);

    /* Rectangular transpose, same modulus */
    for (rep = 0; rep < 1000; rep++)
    {
        r = n_randint(state, 200);
        c = n_randint(state, 200);
        do n = n_randtest_not_zero(state);
        while (n == UWORD(1));
        nmod_init(&mod, n);
        nmod_sparse_mat_init(A, r, c, mod);
        nmod_sparse_mat_init(B, c, r, mod);
        nmod_sparse_mat_init(C, r, c, mod);

        nmod_sparse_mat_randtest(A, state, 0, c);
        nmod_sparse_mat_randtest(B, state, 0, r);
        nmod_sparse_mat_randtest(C, state, 0, c);

        nmod_sparse_mat_transpose(B, A);
        nmod_sparse_mat_transpose(C, B);
        
        if (!nmod_sparse_mat_equal(C, A))
        {
            flint_printf("FAIL: C != A\n");
            abort();
        }

        nmod_sparse_mat_clear(A);
        nmod_sparse_mat_clear(B);
        nmod_sparse_mat_clear(C);
    }

    FLINT_TEST_CLEANUP(state);
    
    flint_printf("PASS\n");
    return 0;
}
