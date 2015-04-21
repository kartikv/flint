/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2014 Fredrik Johansson

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpz_mat.h"
#include "ulong_extras.h"

int should_have_hadamard(int n)
{
    if (n <= 2)
        return 1;

    if (n % 4 != 0)
        return 0;

    if (n <= 300 && n != 92 && n != 116 && n != 156 && n != 172 && n != 184 &&
        n != 188 && n != 232 && n != 236 && n != 260 && n != 268 && n != 292)
        return 1;

    return 0;
}

int
main(void)
{
    int n;
    FLINT_TEST_INIT(state);
    
    flint_printf("hadamard....");
    fflush(stdout);

    for (n = 0; n <= 300; n++)
    {
        fmpz_mat_t h;
        int success;

        fmpz_mat_init(h, n, n);
        success = fmpz_mat_hadamard(h);

        if (success)
        {
            if (!fmpz_mat_is_hadamard(h))
            {
                printf("FAIL: output is not a Hadamard matrix\n");
                printf("n = %d\n\n", n);
                fmpz_mat_print_pretty(h); printf("\n\n");
                abort();
            }
        }
        else if (should_have_hadamard(n))
        {
            printf("FAIL: expected Hadamard matrix of size %d to work\n\n", n);
            abort();
        }

        fmpz_mat_clear(h);
    }

    FLINT_TEST_CLEANUP(state);
    flint_printf("PASS\n");
    return 0;
}