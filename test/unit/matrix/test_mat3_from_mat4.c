#include "unit_test.h"

static void	test_extracts_basis(void)
{
	t_mat3	basis;
	t_mat4	m;
	t_mat3	extracted;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	m = mat4_basis(&basis, vec3(9, 9, 9));
	extracted = mat3_from_mat4(&m);
	CHECK(mat3_eq(&extracted, &basis));
}

/* it just copies the upper-left 3x3, whatever the matrix means (or does
not mean): 4th row/col and their values are ignored entirely. */
static void	test_ignores_fourth_row_and_column(void)
{
	t_mat4	m;
	t_mat3	extracted;
	t_mat3	expected;

	m = (t_mat4){.m = { \
		{1, 2, 3, 100}, \
		{4, 5, 6, 200}, \
		{7, 8, 9, 300}, \
		{400, 500, 600, 700}}};
	extracted = mat3_from_mat4(&m);
	expected = mat3_from_columns(vec3(1, 4, 7), vec3(2, 5, 8), vec3(3, 6, 9));
	CHECK(mat3_eq(&extracted, &expected));
}

int	main(void)
{
	test_extracts_basis();
	test_ignores_fourth_row_and_column();
	return (UNIT_TEST_SUMMARY());
}
