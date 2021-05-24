/*
    Copyright (C) 2010 Fredrik Johansson
    Copyright (C) 2020 Kartik Venkatram

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by th e Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <http://www.gnu.org/licenses/>.
*/


#include "fq_sparse_mat.h"

#ifdef T
#undef T
#endif

#define T fq
#define CAP_T FQ
#include "fq_sparse_mat_templates/rref.c"
#undef CAP_T
#undef T