#include "unit_test.h"

/* m * v: each row of m dotted with v. Picking v = a basis vector reads
back the matching column. */
static void	test_reads_back_columns(void)
{
	t_mat3	basis;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	CHECK(vec3_eq(mat3_mul_vec3(&basis, vec3(1, 0, 0)), vec3(0, 1, 0)));
	CHECK(vec3_eq(mat3_mul_vec3(&basis, vec3(0, 1, 0)), vec3(-1, 0, 0)));
	CHECK(vec3_eq(mat3_mul_vec3(&basis, vec3(0, 0, 1)), vec3(0, 0, 1)));
}

/* a general vector is the matching linear combination of the columns:
2*c0 + 3*c1 + 4*c2. */
static void	test_general_linear_combination(void)
{
	t_mat3	basis;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	CHECK(vec3_eq(mat3_mul_vec3(&basis, vec3(2, 3, 4)), vec3(-3, 2, 4)));
}

/* the identity matrix leaves every vector unchanged. */
static void	test_identity(void)
{
	t_mat3	id;

	id = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	CHECK(vec3_eq(mat3_mul_vec3(&id, vec3(7, -3, 2)), vec3(7, -3, 2)));
}

int	main(void)
{
	test_reads_back_columns();
	test_general_linear_combination();
	test_identity();
	return (UNIT_TEST_SUMMARY());
}
