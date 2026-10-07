#include "unit_test.h"

/* M = translate(origin) * basis * scale: each basis column scaled, then
the origin dropped into the 4th column. */
static void	test_places_scaled_basis_and_origin(void)
{
	t_mat3	basis;
	t_mat4	m;
	t_mat4	expected;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	m = mat4_local_to_world(&basis, vec3(5, 6, 7), vec3(2, 3, 4));
	expected = (t_mat4){.m = { \
		{0, -3, 0, 5}, \
		{2, 0, 0, 6}, \
		{0, 0, 4, 7}, \
		{0, 0, 0, 1}}};
	CHECK(mat4_eq(&m, &expected));
}

/* identity basis + zero origin collapses to a plain scale matrix. */
static void	test_identity_basis_is_plain_scale(void)
{
	t_mat3	basis;
	t_mat4	m;
	t_mat4	expected;

	basis = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	m = mat4_local_to_world(&basis, vec3(0, 0, 0), vec3(2, 3, 4));
	expected = mat4_scale(vec3(2, 3, 4));
	CHECK(mat4_eq(&m, &expected));
}

/* a negative scale mirrors that axis of the basis. */
static void	test_negative_scale_mirrors_axis(void)
{
	t_mat3	basis;
	t_mat4	m;
	t_vec3	p;

	basis = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	m = mat4_local_to_world(&basis, vec3(0, 0, 0), vec3(-1, 1, 1));
	p = mat4_transform_point(&m, vec3(1, 0, 0));
	CHECK(vec3_eq(p, vec3(-1, 0, 0)));
}

int	main(void)
{
	test_places_scaled_basis_and_origin();
	test_identity_basis_is_plain_scale();
	test_negative_scale_mirrors_axis();
	return (UNIT_TEST_SUMMARY());
}
