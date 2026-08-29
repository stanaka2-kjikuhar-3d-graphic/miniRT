#include "unit_test.h"

/* inverse of a pure scale is just the reciprocal scale. */
static void	test_inverse_of_scale(void)
{
	t_mat4	s;
	t_mat4	inv;
	t_mat4	expected;

	s = mat4_scale(vec3(2, 4, 5));
	inv = mat4_inverse(&s);
	expected = mat4_scale(vec3(1.0f / 2.0f, 1.0f / 4.0f, 1.0f / 5.0f));
	CHECK(mat4_eq(&inv, &expected));
}

/* general case: M * inverse(M) == identity, and it undoes M on a point. */
static void	test_round_trip(void)
{
	t_mat4	rot;
	t_mat3	basis;
	t_mat4	m;
	t_mat4	inv;
	t_mat4	should_be_id;
	t_mat4	id;
	t_vec3	p;

	rot = mat4_rotate(vec3(0, 0, 1), 90.0f);
	basis = mat3_from_mat4(&rot);
	m = mat4_local_to_world(&basis, vec3(5, -2, 7), vec3(2, 3, 4));
	inv = mat4_inverse(&m);
	should_be_id = mat4_mul(&m, &inv);
	id = mat4_identity();
	CHECK(mat4_eq(&should_be_id, &id));
	p = vec3(1, 2, 3);
	CHECK(vec3_eq(mat4_transform_point(&inv, mat4_transform_point(&m, p)), p));
}

/* the identity matrix is its own inverse. */
static void	test_inverse_of_identity(void)
{
	t_mat4	id;
	t_mat4	inv;

	id = mat4_identity();
	inv = mat4_inverse(&id);
	CHECK(mat4_eq(&inv, &id));
}

/* inverting twice gets back the original matrix. */
static void	test_double_inverse(void)
{
	t_mat4	m;
	t_mat4	once;
	t_mat4	back;

	m = mat4_scale(vec3(2, 4, 5));
	once = mat4_inverse(&m);
	back = mat4_inverse(&once);
	CHECK(mat4_eq(&back, &m));
}

int	main(void)
{
	test_inverse_of_scale();
	test_round_trip();
	test_inverse_of_identity();
	test_double_inverse();
	return (UNIT_TEST_SUMMARY());
}
