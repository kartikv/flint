/*
    Copyright (C) 2010 Fredrik Johansson

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <string.h>
#include "flint.h"
#include "fmpz_sparse_mat.h"

void
fmpz_sparse_mat_randtest_unsigned(fmpz_sparse_mat_t M, flint_rand_t state, slong min_nnz, slong max_nnz, flint_bitcnt_t bits)
{
    slong i, nnz;

    for (i = 0; i < M->r; ++i)
    {
        nnz = n_randint(state, max_nnz+1);
        nnz = FLINT_MAX(nnz, min_nnz);
        fmpz_sparse_vec_randtest_unsigned(&M->rows[i], state, nnz, M->c, bits);
    }
}

