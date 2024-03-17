#include <stdlib.h>
#include "gr_sparse_vec.h"

typedef struct
{
    slong col;
    slong i;
}
gr_sparse_vec_slong_sorter_t;

static int gr_sparse_vec_slong_cmp(const void* a, const void* b)
{
    slong ak = ((gr_sparse_vec_slong_sorter_t*)(a))->col;
    slong bk = ((gr_sparse_vec_slong_sorter_t*)(b))->col;
    return (ak < bk ? -1 : (ak > bk ? 1 : 0));
}



int
gr_sparse_vec_set_from_entries(gr_sparse_vec_t vec, ulong * inds, gr_srcptr entries, slong nnz, gr_ctx_t ctx)
{
    slong i,j,sz,new_nnz;
    int status;
    gr_sparse_vec_slong_sorter_t *si;
    si = flint_malloc(nnz * sizeof(gr_sparse_vec_slong_sorter_t));
    for (i = 0; i < nnz; i++)
    {
        si[i].col = inds[i];
        si[i].i = i;
    }
    qsort(si, nnz, sizeof(gr_sparse_vec_slong_sorter_t), gr_sparse_vec_slong_cmp);
    /* Since the columns are sorted, we can just test the last to make sure all the columns fit */
    if (nnz > 0 && si[nnz-1].col >= vec->length)
    {
        flint_free(si);
        return GR_DOMAIN;
    }
    new_nnz = (nnz == 0 ? 0 : 1);
    for (i = 1; i < nnz; i++)
    {
        if (si[i-1].col != si[i].col)
            new_nnz += 1;
    }
    gr_sparse_vec_fit_nnz(vec, new_nnz, ctx);
    sz = ctx->sizeof_elem;
    status = GR_SUCCESS;
    j = -1; /* j tracks the current index we are going to put the nonzero in the sparse vector storage */
    /* i tracks where in the column-sorted list of nonzeros we are pulling from */
    for (i = 0; i < nnz && status == GR_SUCCESS; i++)
    {
        /* If it's a new column, do a set; otherwise do an accumulate */
        if (i == 0 || si[i-1].col != si[i].col)
        {
            if (j == -1 || (T_FALSE == gr_is_zero(GR_ENTRY(vec->entries, j, sz), ctx))) /* Only move to the next target if the current one is nonzero */
            {
                j++;
                if (j >= new_nnz)
                {
                    flint_free(si);
                    return GR_UNABLE;  /* This is consistency check */
                }
            }
            vec->inds[j] = si[i].col;
            status |= gr_set(GR_ENTRY(vec->entries, j, sz), GR_ENTRY(entries, si[i].i, sz), ctx);
        }
        else
        {
            if (vec->inds[j] != inds[si[i].i]) /* Consistency check that we're accumulating into the correct column */
                status |= GR_UNABLE;
            status |= gr_add(GR_ENTRY(vec->entries, j, sz), GR_ENTRY(vec->entries, j, sz), GR_ENTRY(entries, si[i].i, sz), ctx);
        }
    }
    /* Finally, figure out whether the last entry is zero (in which case it doesn't count), and set nnz accordingly */
    vec->nnz = (T_FALSE == gr_is_zero(GR_ENTRY(vec->entries, j, sz), ctx) ? j+1 : j);
    flint_free(si);
    return status;
}

int
gr_sparse_vec_set_from_entries_sorted_deduped(gr_sparse_vec_t vec, ulong * sorted_deduped_inds, gr_srcptr entries, slong nnz, gr_ctx_t ctx)
{
    slong i,j,sz;
    int status;
    gr_sparse_vec_fit_nnz(vec, nnz, ctx);
    sz = ctx->sizeof_elem;
    j = 0;
    status = GR_SUCCESS;
    for (i = 0; i < nnz && status == GR_SUCCESS; i++)
    {
        if (T_FALSE == gr_is_zero(GR_ENTRY(entries, i, sz), ctx))
        {
            vec->inds[j] = sorted_deduped_inds[i];
            status |= gr_set(GR_ENTRY(vec->entries, j, sz), GR_ENTRY(entries, i, sz), ctx);
            j++;
        }
    }
    vec->nnz = j;
    return status;
}


