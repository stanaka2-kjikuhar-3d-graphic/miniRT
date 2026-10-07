#include "unit_test.h"

/* cofactor = (-1)^(row+col) * minor, on the same fixture as
test_mat4_minor.c so the sign flip is the only new thing checked. */
static void	test_block_diagonal_matrix(void)
{
	t_mat4	m;

	m = (t_mat4){.m = { \
		{1, 2, 0, 0}, \
		{3, 4, 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}};
	CHECK(approx(mat4_cofactor(&m, 0, 0), 4.0f));
	CHECK(approx(mat4_cofactor(&m, 0, 1), -3.0f));
	CHECK(approx(mat4_cofactor(&m, 1, 0), -2.0f));
	CHECK(approx(mat4_cofactor(&m, 2, 2), -2.0f));
}

/* a negative minor combined with an odd (row+col) flips back to
positive: the sign rule must not just negate everything. */
static void	test_sign_flip_on_negative_minor(void)
{
	t_mat4	m;

	m = (t_mat4){.m = { \
		{2, -1, 0, 0}, \
		{1, 3, 0, 0}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}};
	CHECK(approx(mat4_cofactor(&m, 0, 0), 3.0f));
	CHECK(approx(mat4_cofactor(&m, 0, 1), -1.0f));
	CHECK(approx(mat4_cofactor(&m, 1, 0), 1.0f));
	CHECK(approx(mat4_cofactor(&m, 1, 1), 2.0f));
}

int	main(void)
{
	test_block_diagonal_matrix();
	test_sign_flip_on_negative_minor();
	return (UNIT_TEST_SUMMARY());
}
