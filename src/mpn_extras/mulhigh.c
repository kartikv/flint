/*
    Copyright (C) 2024 Albin Ahlbäck
    Copyright (C) 2024 Fredrik Johansson

    Uses code adopted from the GNU MPFR Library.

        Copyright 2005-2024 Free Software Foundation, Inc.
        Contributed by the AriC and Caramba projects, INRIA.

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include <string.h>
#include "mpn_extras.h"

/* Generated by tune-mulhigh.c */
const signed short flint_mpn_mulhigh_k_tab[FLINT_MPN_MULHIGH_K_TAB_SIZE] =
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 14, 14, 16, 15, 15, 18, 18, 
18, 19, 20, 18, 22, 22, 20, 20, 26, 22, 22, 22, 24, 24, 24, 26, 25, 26, 30, 30, 28, 30, 31, 32, 32, 30, 36, 36, 36, 36, 
38, 39, 39, 38, 39, 40, 40, 40, 44, 40, 44, 44, 40, 44, 44, 48, 44, 48, 44, 48, 48, 52, 52, 52, 44, 52, 52, 52, 52, 56, 
60, 60, 52, 60, 60, 52, 52, 60, 64, 72, 56, 60, 72, 60, 60, 60, 76, 64, 60, 60, 72, 60, 72, 80, 72, 72, 80, 72, 68, 76, 
88, 76, 68, 76, 72, 72, 80, 88, 72, 72, 88, 72, 80, 76, 76, 80, 80, 88, 80, 88, 84, 88, 80, 96, 80, 80, 88, 80, 88, 88, 
80, 88, 96, 96, 88, 96, 92, 96, 96, 92, 100, 88, 96, 104, 88, 108, 96, 104, 104, 104, 112, 112, 108, 104, 104, 112, 112, 120, 104, 112, 
120, 112, 112, 120, 124, 124, 116, 124, 108, 120, 124, 116, 120, 120, 116, 120, 124, 120, 120, 140, 120, 120, 120, 120, 144, 120, 132, 144, 136, 140, 
144, 144, 144, 144, 144, 144, 144, 144, 140, 156, 140, 140, 144, 144, 144, 160, 144, 144, 156, 156, 144, 160, 160, 160, 160, 152, 160, 156, 156, 156, 
160, 160, 144, 160, 164, 156, 156, 156, 172, 156, 156, 160, 176, 160, 160, 164, 176, 156, 160, 160, 156, 156, 160, 160, 156, 160, 172, 160, 188, 172, 
172, 172, 160, 172, 176, 160, 160, 176, 180, 176, 164, 188, 192, 176, 172, 188, 188, 188, 172, 188, 192, 188, 180, 192, 192, 188, 188, 192, 188, 188, 
188, 188, 192, 160, 156, 204, 160, 164, 164, 164, 164, 176, 180, 168, 172, 184, 188, 200, 216, 188, 164, 188, 220, 188, 208, 176, 180, 188, 172, 188, 
184, 188, 204, 208, 220, 196, 220, 196, 208, 212, 188, 220, 176, 176, 184, 192, 208, 184, 188, 196, 204, 244, 208, 212, 212, 228, 256, 188, 204, 196, 
188, 192, 192, 192, 212, 188, 292, 212, 220, 236, 228, 248, 260, 224, 264, 196, 200, 196, 212, 208, 204, 216, 208, 228, 216, 220, 252, 220, 268, 264, 
284, 268, 300, 220, 208, 212, 220, 236, 244, 224, 252, 252, 260, 264, 256, 256, 292, 272, 288, 292, 328, 224, 256, 236, 252, 268, 256, 252, 260, 272, 
284, 296, 300, 280, 300, 284, 252, 236, 328, 324, 264, 264, 256, 264, 280, 268, 284, 284, 292, 304, 260, 304, 264, 256, 328, 328, 260, 276, 328, 284, 
276, 296, 300, 320, 320, 304, 328, 304, 272, 268, 280, 268, 288, 292, 288, 284, 316, 288, 328, 328, 300, 328, 328, 280, 264, 328, 300, 328, 316, 324, 
300, 324, 300, 324, 316, 316, 328, 348, 276, 376, 288, 296, 296, 304, 320, 316, 328, 328, 324, 328, 340, 384, 348, 376, 300, 396, 304, 300, 304, 324, 
300, 324, 328, 328, 328, 440, 448, 384, 376, 456, 464, 384, 376, 472, 480, 376, 352, 328, 376, 352, 376, 392, 392, 384, 456, 456, 480, 448, 456, 456, 
472, 472, 472, 352, 464, 472, 472, 472, 480, 440, 480, 480, 480, 480, 456, 472, 472, 464, 464, 464, 456, 472, 480, 472, 480, 480, 480, 480, 448, 456, 
480, 448, 456, 464, 456, 464, 456, 480, 472, 464, 464, 472, 472, 472, 480, 472, 480, 480, 472, 480, 480, 480, 480, 464, 464, 464, 456, 472, 464, 480, 
472, 472, 480, 472, 480, 480, 464, 464, 472, 464, 472, 472, 480, 464, 480, 472, 480, 480, 576, 576, 560, 480, 472, 480, 568, 480, 480, 464, 480, 472, 
480, 576, 480, 552, 560, 560, 560, 560, 568, 560, 560, 576, 576, 560, 568, 472, 480, 480, 544, 568, 552, 544, 560, 544, 560, 568, 552, 576, 568, 560, 
576, 576, 568, 576, 560, 576, 568, 536, 576, 568, 560, 544, 560, 552, 560, 568, 560, 576, 568, 560, 560, 560, 568, 576, 568, 576, 576, 576, 576, 544, 
576, 576, 568, 576, 560, 576, 576, 576, 544, 552, 568, 576, 552, 560, 576, 560, 568, 560, 576, 560, 544, 576, 576, 576, 576, 568, 576, 568, 560, 576, 
552, 552, 576, 560, 568, 568, 568, 576, 576, 576, 560, 552, 576, 560, 568, 560, 576, 560, 568, 560, 568, 568, 568, 576, 552, 576, 560, 576, 576, 560, 
568, 576, 568, 576, 576, 576, 576, 560, 576, 568, 568, 568, 560, 560, 576, 576, 568, 568, 576, 560, 576, 576, 568, 576, 560, 576, 576, 568, 576, 568, 
576, 568, 576, 576, 568, 576, 576, 576, 576, 568, 576, 576, 568, 568, 576, 576, 784, 576, 776, 576, 568, 576, 576, 576, 576, 576, 576, 576, 776, 776, 
776, 776, 776, 776, 776, 784, 776, 776, 784, 776, 776, 776, 800, 776, 776, 776, 776, 776, 776, 800, 776, 808, 792, 800, 776, 792, 776, 776, 776, 776, 
792, 776, 776, 784, 792, 784, 800, 776, 784, 808, 784, 776, 776, 776, 808, 784, 792, 776, 792, 832, 800, 800, 816, 792, 816, 816, 856, 808, 848, 824, 
870, 832, 792, 776, 784, 784, 784, 784, 800, 792, 800, 792, 784, 800, 800, 800, 816, 824, 824, 824, 832, 816, 816, 832, 824, 824, 848, 832, 856, 856, 
840, 872, 864, 872, 872, 880, 880, 880, 872, 888, 880, 880, 872, 880, 880, 880, 840, 872, 872, 848, 880, 848, 856, 840, 848, 840, 880, 872, 856, 872, 
856, 888, 880, 872, 888, 880, 872, 920, 888, 872, 880, 872, 888, 888, 888, 880, 880, 928, 880, 928, 928, 928, 920, 920, 904, 912, 880, 904, 928, 872, 
872, 880, 888, 880, 896, 880, 872, 896, 888, 896, 896, 928, 904, 896, 896, 912, 904, 904, 920, 880, 912, 920, 928, 928, 880, 920, 920, 880, 888, 904, 
896, 904, 928, 896, 912, 896, 912, 920, 912, 912, 928, 928, 928, 920, 928, 928, 928, 928, 928, 928, 912, 904, 912, 896, 904, 904, 920, 920, 920, 928, 
928, 920, 928, 928, 928, 912, 928, 912, 928, 928, 928, 912, 912, 912, 928, 928, 928, 896, 928, 928, 912, 928, 928, 928, 912, 928, 912, 928, 928, 912, 
928, 912, 928, 928, 928, 928, 928, 912, 928, 928, 928, 928, 912, 912, 928, 912, 928, 1024, 928, 928, 928, 928, 928, 928, 1056, 912, 928, 928, 1024, 1024, 
928, 928, 1024, 928, 928, 928, 928, 928, 928, 1040, 1040, 928, 1056, 1024, 1072, 1024, 1040, 1040, 1040, 1024, 1088, 1056, 1056, 1088, 1040, 1056, 1072, 1072, 1056, 1056, 
1024, 1088, 1040, 1024, 1040, 1040, 1024, 1056, 1056, 1056, 1040, 1072, 1056, 1040, 1056, 1056, 1056, 1056, 1056, 1056, 1056, 1120, 1056, 1088, 1056, 1120, 1088, 1072, 1104, 1104, 
1104, 1120, 1088, 1088, 1072, 1088, 1120, 1104, 1088, 1104, 1088, 1072, 1104, 1088, 1120, 1088, 1072, 1072, 1072, 1088, 1088, 1072, 1072, 1088, 1104, 1152, 1104, 1104, 1088, 1104, 
1136, 1088, 1104, 1152, 1152, 1152, 1136, 1120, 1136, 1152, 1120, 1152, 1088, 1120, 1104, 1120, 1136, 1104, 1136, 1088, 1136, 1104, 1088, 1104, 1120, 1104, 1104, 1120, 1136, 1136, 
1120, 1136, 1136, 1136, 1120, 1152, 1152, 1136, 1152, 1136, 1152, 1152, 1104, 1152, 1120, 1136, 1120, 1120, 1152, 1120, 1136, 1152, 1136, 1152, 1120, 1152, 1136, 1136, 1136, 1136, 
1136, 1152, 1152, 1152, 1152, 1120, 1120, 1152, 1136, 1136, 1136, 1152, 1152, 1120, 1152, 1152, 1152, 1152, 1152, 1104, 1152, 1152, 1120, 1136, 1152, 1120, 1152, 1136, 1152, 1152, 
1152, 1152, 1152, 1152, 1136, 1152, 1136, 1152, 1152, 1136, 1120, 1136, 1152, 1152, 1152, 1136, 1152, 1152, 1136, 1136, 1152, 1136, 1152, 1136, 1136, 1152, 1152, 1152, 1152, 1152, 
1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 
1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 
1152, 1152, 1152, 1152, 1152, 1136, 1152, 1136, 1152, 1152, 1152, 1136, 1152, 1152, 1136, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 
1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 
1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 
1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1136, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 1152, 
1152, 1344, 1152, 1344, 1344, 1344, 1152, 1152, 1152, 1152, 1344, 1328, 1328, 1328, 1152, 1344, 1152, 1344, 1152, 1344, 1152, 1152, 1328, 1152, 1328, 1344, 1328, 1344, 1328, 1344, 
1344, 1312, 1328, 1328, 1328, 1344, 1344, 1344, 1328, 1344, 1328, 1344, 1344, 1344, 1344, 1344, 1344, 1328, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1344, 1328, 1344, 
1328, 1344, 1344, 1344, 1344, 1328, 1344, 1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 
1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1573, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1583, 1568, 1568, 1552, 1568, 1552, 1568, 
1568, 1568, 1584, 1568, 1584, 1568, 1568, 1568, 1552, 1552, 1552, 1568, 1552, 1584, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1552, 1584, 1552, 1584, 1552, 1617, 1568, 1584, 
1552, 1552, 1584, 1584, 1552, 1625, 1626, 1627, 1628, 1629, 1630, 1631, 1632, 1633, 1634, 1632, 1636, 1632, 1638, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 
1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1632, 1648, 1669, 1648, 1671, 1632, 1664, 1648, 1632, 1648, 1648, 1648, 1632, 
1632, 1632, 1632, 1632, 1648, 1664, 1632, 1632, 1632, 1648, 1664, 1632, 1632, 1664, 1632, 1632, 1632, 1632, 1632, 1632, 1680, 1664, 1648, 1664, 1648, 1648, 1648, 1648, 1648, 1648, 
1680, 1664, 1680, 1696, 1680, 1680, 1664, 1680, 1680, 1648, 1632, 1680, 1696, 1632, 1648, 1648, 1632, 1680, 1680, 1664, 1664, 1664, 1648, 1680, 1664, 1680, 1664, 1680, 1664, 1664, 
1680, 1696, 1664, 1696, 1712, 1712, 1696, 1680, 1712, 1696, 1728, 1712, 1696, 1728, 1728, 1712, 1728, 1648, 1680, 1696, 1712, 1696, 1712, 1696, 1696, 1680, 1696, 1696, 1696, 1712, 
1696, 1696, 1696, 1696, 1712, 1728, 1696, 1728, 1696, 1696, 1712, 1728, 1712, 1728, 1712, 1680, 1696, 1728, 1712, 1696, 1696, 1696, 1712, 1712, 1728, 1696, 1728, 1712, 1712, 1728, 
1696, 1696, 1696, 1712, 1696, 1728, 1712, 1712, 1712, 1728, 1696, 1712, 1728, 1728, 1696, 1728, 1728, 1728, 1728, 1728, 1680, 1712, 1728, 1696, 1728, 1728, 1728, 1728, 1696, 1728, 
1712, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1712, 1712, 1728, 1728, 1728, 1728, 1696, 1728, 1712, 1712, 1712, 1712, 1728, 1712, 1712, 1712, 1728, 1712, 1728, 1728, 1728, 
1728, 1712, 1728, 1728, 1712, 1728, 1728, 1712, 1712, 1728, 1712, 1712, 1728, 1728, 1712, 1728, 1712, 1728, 1712, 1712, 1728, 1728, 1728, 1712, 1728, 1728, 1728, 1728, 1728, 1712, 
1728, 1712, 1712, 1712, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1712, 1712, 1728, 1728, 1728, 1712, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 1728, 
1728, 1728, 1712, 1728, 1728, 1824, 1728, 1728, 1728, 1728, 1824, 1728, 1840, 1728, 1728, 1728, 1728, 1856, 1728, 1840, 1856, 1856, 1840, 1728, 1728, 1856, 1856, 1856, 1856, 1728, 
1728, 1856, 1856, 1728, 1856, 1728, 1856, 1728, 1840, 1856, 1856, 1840, 1856, 1856, 1856, 1840, 1856, 1856, 1856, 1856, 1856, 1856, 1856, 1840, 1904, 1856, 1856, 1840, 1840, 1856, 
1856, 1840, 1856, 1840, 1856, 1856, 1856, 1856, 1952, 1856, 1856, 1856, 1856, 1952, 1904, 1904, 1856, 1856, 1856, 1920, 1952, 2001, 1952, 1984, 1952, 1936, 1952, 1904, 1968, 1920, 
1984, 1920, 1968, 1920, 1936, 1856, 2000, 1920, 1936, 1952, 2000, 1968, 1984, 1968, 1984, 2000, 1952, 2000, 2016, 1984, 2000, 2016, 1984, 1664, 2016, 1984, 2016, 1968, 2016, 2016, 
1744, 2016, 2016, 1968, 2000, 1728, 1712, 1696, };

void
_flint_mpn_mulhigh_n_mulders_recursive(mp_ptr rp, mp_srcptr np, mp_srcptr mp, mp_size_t n)
{
    mp_limb_t cy;
    mp_size_t l;
    slong k;

    if (FLINT_HAVE_MULHIGH_FUNC(n))
    {
        rp[n - 1] = flint_mpn_mulhigh_func_tab[n](rp + n, np, mp);
        return;
    }

    if (n < FLINT_MPN_MULHIGH_K_TAB_SIZE)
        k = flint_mpn_mulhigh_k_tab[n];
    else
        k = 3 * (n / 4);

    if (k == 0)
    {
        rp[n - 1] = _flint_mpn_mulhigh_basecase(rp + n, np, mp, n);
        return;
    }

    FLINT_ASSERT(k >= (n + 4) / 2);

    if (k == n)
    {
        flint_mpn_mul_n(rp, np, mp, n);
        return;
    }

    l = n - k;
    flint_mpn_mul_n(rp + 2 * l, np + l, mp + l, k);
    _flint_mpn_mulhigh_n_mulders_recursive(rp, np + k, mp, l);
    cy = mpn_add_n(rp + n - 1, rp + n - 1, rp + l - 1, l + 1);
    _flint_mpn_mulhigh_n_mulders_recursive(rp, np, mp + k, l);
    cy += mpn_add_n(rp + n - 1, rp + n - 1, rp + l - 1, l + 1);
    MPN_INCR_U(rp + n + l, k, cy);
}

mp_limb_t
_flint_mpn_mulhigh_n_mulders(mp_ptr res, mp_srcptr u, mp_srcptr v, mp_size_t n)
{
    mp_ptr tmp, tr, tu, tv;
    mp_limb_t bot;
    TMP_INIT;

    TMP_START;
    tmp = TMP_ALLOC(sizeof(mp_limb_t) * (4 * (n + 1)));
    tu = tmp;
    tv = tu + (n + 1);
    tr = tv + (n + 1);
    tu[0] = 0;
    tv[0] = 0;
    flint_mpn_copyi(tu + 1, u, n);
    flint_mpn_copyi(tv + 1, v, n);
    _flint_mpn_mulhigh_n_mulders_recursive(tr, tu, tv, n + 1);
    flint_mpn_copyi(res, tr + n + 2, n);
    bot = tr[n + 1];

    TMP_END;
    return bot;
}

mp_limb_t
_flint_mpn_mulhigh_n_mul(mp_ptr res, mp_srcptr u, mp_srcptr v, mp_size_t n)
{
    mp_ptr tmp;
    mp_limb_t bot;
    tmp = flint_malloc(sizeof(mp_limb_t) * (2 * n));
    flint_mpn_mul_n(tmp, u, v, n);
    memcpy(res, tmp + n, sizeof(mp_limb_t) * n);
    bot = tmp[n - 1];
    flint_free(tmp);
    return bot;
}

mp_limb_t
_flint_mpn_mulhigh_n(mp_ptr res, mp_srcptr u, mp_srcptr v, mp_size_t n)
{
    if (n <= FLINT_MPN_MULHIGH_MULDERS_CUTOFF)
        return _flint_mpn_mulhigh_basecase(res, u, v, n);
    else if (n <= FLINT_MPN_MULHIGH_MUL_CUTOFF)
        return _flint_mpn_mulhigh_n_mulders(res, u, v, n);
    else
        return _flint_mpn_mulhigh_n_mul(res, u, v, n);
}
