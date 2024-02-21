#include "test_helpers.h"
#include "gr_sparse_vec.h"

#define CHECK_TEST(x, name) { if (GR_SUCCESS != (x)) { flint_printf("FAIL %s\n", (name)); flint_abort(); } }



int
test_conversion(flint_rand_t state, gr_ctx_t ctx)
{
    slong i;
    slong N = 100;
    slong n_tests = 20;
    slong sz = ctx->sizeof_elem;
    int status = GR_SUCCESS;
    gr_sparse_vec_t vec;
    gr_vec_t dvec, dvec2;
    gr_vec_init(dvec, N, ctx);
    gr_vec_init(dvec2, N, ctx);
    status |= gr_sparse_vec_init(vec, N, ctx);

    for (i = 0; i < n_tests; i++)
    {
        status |= _gr_vec_randtest(GR_VEC_ENTRY(dvec, 0, sz), state, N, ctx);
        status |= gr_sparse_vec_from_dense(vec, GR_VEC_ENTRY(dvec, 0, sz), N, ctx);
        status |= gr_sparse_vec_to_dense(GR_VEC_ENTRY(dvec2, 0, sz), vec, ctx);
        if (T_TRUE != _gr_vec_equal(GR_VEC_ENTRY(dvec, 0, sz), GR_VEC_ENTRY(dvec2, 0, sz), N, ctx))
            return GR_TEST_FAIL;
    }
    status |= gr_sparse_vec_clear(vec, ctx);
    gr_vec_clear(dvec, ctx);
    gr_vec_clear(dvec2, ctx);
    return status;
}

TEST_FUNCTION_START(gr_sparse_vec_conversion, state)
{   
    gr_ctx_t ctx;
    gr_ctx_init_random(ctx, state);
    CHECK_TEST(test_conversion(state, ctx), "Conversion from and to dense");
    gr_ctx_clear(ctx);
    TEST_FUNCTION_END(state);
}
