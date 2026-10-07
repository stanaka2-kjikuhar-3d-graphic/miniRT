#include "unit_test.h"

static void	test_places_basis_and_origin(void)
{
	t_mat3	basis;
	t_mat4	m;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	m = mat4_basis(&basis, vec3(5, 6, 7));
	CHECK(approx(m.m[0][3], 5.0f));
	CHECK(approx(m.m[1][3], 6.0f));
	CHECK(approx(m.m[2][3], 7.0f));
	CHECK(approx(m.m[3][3], 1.0f));
	CHECK(approx(m.m[3][0], 0.0f) && approx(m.m[3][1], 0.0f) \
		&& approx(m.m[3][2], 0.0f));
	CHECK(approx(m.m[0][0], basis.m[0][0]) \
		&& approx(m.m[1][2], basis.m[1][2]));
}

/* identity basis + zero origin is the identity matrix. */
static void	test_identity_basis_and_origin(void)
{
	t_mat3	basis;
	t_mat4	m;
	t_mat4	id;

	basis = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	m = mat4_basis(&basis, vec3(0, 0, 0));
	id = mat4_identity();
	CHECK(mat4_eq(&m, &id));
}

/* a negative origin lands as-is in the 4th column. */
static void	test_negative_origin(void)
{
	t_mat3	basis;
	t_mat4	m;

	basis = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	m = mat4_basis(&basis, vec3(-1, -2, -3));
	CHECK(approx(m.m[0][3], -1.0f) && approx(m.m[1][3], -2.0f) \
		&& approx(m.m[2][3], -3.0f));
}

int	main(void)
{
	test_places_basis_and_origin();
	test_identity_basis_and_origin();
	test_negative_origin();
	return (UNIT_TEST_SUMMARY());
}
