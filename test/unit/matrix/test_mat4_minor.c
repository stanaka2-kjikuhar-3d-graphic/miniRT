#include "unit_test.h"

/*
| 1 2 0 0 |
| 3 4 0 0 |
| 0 0 1 0 |
| 0 0 0 1 |
3x3 determinants of m with one row/col removed, computed by hand.
*/
static void	test_block_diagonal_matrix(void)
{
	t_mat4	m;

	m = (t_mat4){.m = { \
		{1, 2, 0, 0}, \
		{3, 4, 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}};
	CHECK(approx(mat4_minor(&m, 0, 0), 4.0f));
	CHECK(approx(mat4_minor(&m, 0, 1), 3.0f));
	CHECK(approx(mat4_minor(&m, 1, 0), 2.0f));
	CHECK(approx(mat4_minor(&m, 2, 2), -2.0f));
}

/*
| 2 -1 0 0 |
| 1  3 0 0 |
| 0  0 1 0 |
| 0  0 0 1 |
same idea with negative entries, to make sure signs are not lost.
*/
static void	test_matrix_with_negative_entries(void)
{
	t_mat4	m;

	m = (t_mat4){.m = { \
		{2, -1, 0, 0}, \
		{1, 3, 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}};
	CHECK(approx(mat4_minor(&m, 0, 0), 3.0f));
	CHECK(approx(mat4_minor(&m, 0, 1), 1.0f));
	CHECK(approx(mat4_minor(&m, 1, 0), -1.0f));
	CHECK(approx(mat4_minor(&m, 1, 1), 2.0f));
}

/* identity: removing any row/col leaves an identity-like block, det 1. */
static void	test_identity(void)
{
	t_mat4	id;

	id = mat4_identity();
	CHECK(approx(mat4_minor(&id, 0, 0), 1.0f));
	CHECK(approx(mat4_minor(&id, 3, 3), 1.0f));
}

int	main(void)
{
	test_block_diagonal_matrix();
	test_matrix_with_negative_entries();
	test_identity();
	return (UNIT_TEST_SUMMARY());
}
