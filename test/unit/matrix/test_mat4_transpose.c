#include "unit_test.h"

/* transpose(m)[row][col] == m[col][row] for an arbitrary matrix. */
static void	test_swaps_rows_and_cols(void)
{
	t_mat4	m;
	t_mat4	t;
	int		row;
	int		col;

	m = mat4_basis(&(t_mat3){.m = { \
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, vec3(10, 11, 12));
	t = mat4_transpose(&m);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			CHECK(approx(t.m[row][col], m.m[col][row]));
			++col;
		}
		++row;
	}
}

/* transposing twice gets back the original matrix. */
static void	test_involution(void)
{
	t_mat4	m;
	t_mat4	once;
	t_mat4	back;

	m = mat4_basis(&(t_mat3){.m = { \
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, vec3(10, 11, 12));
	once = mat4_transpose(&m);
	back = mat4_transpose(&once);
	CHECK(mat4_eq(&back, &m));
}

/* identity is symmetric, so its transpose is itself. */
static void	test_identity_is_fixed_point(void)
{
	t_mat4	id;
	t_mat4	t;

	id = mat4_identity();
	t = mat4_transpose(&id);
	CHECK(mat4_eq(&t, &id));
}

int	main(void)
{
	test_swaps_rows_and_cols();
	test_involution();
	test_identity_is_fixed_point();
	return (UNIT_TEST_SUMMARY());
}
