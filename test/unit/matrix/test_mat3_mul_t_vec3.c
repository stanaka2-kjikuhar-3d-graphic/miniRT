#include "unit_test.h"

/* transpose(m) * v: result.x = dot(column 0, v), etc. */
static void	test_dots_v_with_each_column(void)
{
	t_mat3	basis;
	t_vec3	result;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	result = mat3_mul_t_vec3(&basis, vec3(2, 3, 4));
	CHECK(vec3_eq(result, vec3(3, -2, 4)));
}

/* same rule on a non-orthonormal matrix: no assumption about the basis
being a rotation, this is a plain transpose-then-multiply. */
static void	test_non_orthonormal_matrix(void)
{
	t_mat3	m;
	t_vec3	result;

	m = mat3_from_columns(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
	result = mat3_mul_t_vec3(&m, vec3(1, 0, 0));
	CHECK(vec3_eq(result, vec3(1, 4, 7)));
}

/* the identity matrix is its own transpose, so it still leaves v alone. */
static void	test_identity(void)
{
	t_mat3	id;

	id = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	CHECK(vec3_eq(mat3_mul_t_vec3(&id, vec3(5, -1, 2)), vec3(5, -1, 2)));
}

int	main(void)
{
	test_dots_v_with_each_column();
	test_non_orthonormal_matrix();
	test_identity();
	return (UNIT_TEST_SUMMARY());
}
