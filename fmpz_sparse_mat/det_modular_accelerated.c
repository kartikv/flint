/*
    Copyright (C) 2011 Fredrik Johansson
    Copyright (C) 2020 Kartik Venkatram

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/

#include "fmpz_sparse_mat.h"

void
fmpz_sparse_mat_det_modular_accelerated(fmpz_t det, const fmpz_sparse_mat_t A, int proved)
{
    fmpz_t d;
    FLINT_ASSERT(A->r == A->c);
    fmpz_init(d);
    fmpz_sparse_mat_det_divisor(d, A);
    fmpz_sparse_mat_det_modular_given_divisor(det, A, d, proved);
    fmpz_clear(d);
}
