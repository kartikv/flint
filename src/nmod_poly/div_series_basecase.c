/*
    Copyright (C) 2016 Fredrik Johansson

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "nmod.h"
#include "nmod_vec.h"
#include "nmod_poly.h"

void
_nmod_poly_div_series_basecase_preinv1(mp_ptr Qinv, mp_srcptr P, slong Plen,
                                mp_srcptr Q, slong Qlen, slong n, mp_limb_t q, nmod_t mod)
{
    slong i, j, l;
    int nlimbs;
    mp_limb_t s;

    Plen = FLINT_MIN(Plen, n);
    Qlen = FLINT_MIN(Qlen, n);

    if (Qlen == 1)
    {
        _nmod_vec_scalar_mul_nmod(Qinv, P, Plen, q, mod);
        _nmod_vec_zero(Qinv + Plen, n - Plen);
    }
    else
    {
        Qinv[0] = nmod_mul(q, P[0], mod);

        nlimbs = _nmod_vec_dot_bound_limbs(FLINT_MIN(n, Qlen), mod);

        for (i = 1; i < n; i++)
        {
            l = FLINT_MIN(i, Qlen - 1);

            NMOD_VEC_DOT(s, j, l, Q[j + 1], Qinv[i - 1 - j], mod, nlimbs);

            if (i < Plen)
                s = nmod_sub(P[i], s, mod);
            else
                s = nmod_neg(s, mod);

            if (q != 1)
                Qinv[i] = nmod_mul(s, q, mod);
            else
                Qinv[i] = s;
        }
    }
}

void
_nmod_poly_div_series_basecase(mp_ptr Qinv, mp_srcptr P, slong Plen,
                                mp_srcptr Q, slong Qlen, slong n, nmod_t mod)
{
    mp_limb_t q;

    q = Q[0];
    if (q != 1)
        q = n_invmod(q, mod.n);

    _nmod_poly_div_series_basecase_preinv1(Qinv, P, Plen, Q, Qlen, n, q, mod);
}

void
nmod_poly_div_series_basecase(nmod_poly_t Q, const nmod_poly_t A,
                                    const nmod_poly_t B, slong n)
{
    slong Alen, Blen;

    Blen = B->length;

    if (n == 0 || Blen == 0 || B->coeffs[0] == 0)
    {
        flint_printf("Exception (nmod_poly_div_series_basecase). Division by zero.\n");
        flint_abort();
    }

    Alen = A->length;

    if (Alen == 0)
    {
        nmod_poly_zero(Q);
        return;
    }

    if (Q != A && Q != B)
    {
        nmod_poly_fit_length(Q, n);
        _nmod_poly_div_series_basecase(Q->coeffs, A->coeffs, Alen, B->coeffs, Blen, n, Q->mod);
    }
    else
    {
        nmod_poly_t t;
        nmod_poly_init2(t, Q->mod.n, n);
        _nmod_poly_div_series_basecase(t->coeffs, A->coeffs, Alen, B->coeffs, Blen, n, Q->mod);
        nmod_poly_swap(Q, t);
        nmod_poly_clear(t);
    }

    Q->length = n;
    _nmod_poly_normalise(Q);
}

