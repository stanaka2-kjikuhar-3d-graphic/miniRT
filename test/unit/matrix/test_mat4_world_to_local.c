#include "unit_test.h"

/*
mat4_world_to_local is documented as the closed-form inverse of
mat4_local_to_world for the same (basis, origin, scale). Verify the
round trip it exists for, on a few different fixtures.
*/
static void	check_round_trip(t_mat3 const *basis, t_vec3 origin, t_vec3 scale)
{
	t_mat4	to_world;
	t_mat4	to_local;
	t_vec3	p;

	to_world = mat4_local_to_world(basis, origin, scale);
	to_local = mat4_world_to_local(basis, origin, scale);
	CHECK(vec3_eq(mat4_transform_point(&to_local, origin), vec3(0, 0, 0)));
	p = vec3(1, 2, 3);
	CHECK(vec3_eq(\
		mat4_transform_point(&to_local, mat4_transform_point(&to_world, p)),
		p));
}

static void	test_rotated_basis_nonuniform_scale(void)
{
	t_mat3	basis;

	basis = mat3_from_columns(vec3(0, 1, 0), vec3(-1, 0, 0), vec3(0, 0, 1));
	check_round_trip(&basis, vec3(5, -2, 7), vec3(2, 3, 4));
}

static void	test_identity_basis_unit_scale(void)
{
	t_mat3	basis;

	basis = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	check_round_trip(&basis, vec3(0, 0, 0), vec3(1, 1, 1));
}

/* extreme non-uniform scale, and an axis-aligned basis rotated on X. */
static void	test_extreme_nonuniform_scale(void)
{
	t_mat4	rot;
	t_mat3	basis;

	rot = mat4_rotate(vec3(1, 0, 0), 37.0f);
	basis = mat3_from_mat4(&rot);
	check_round_trip(&basis, vec3(-3, 4, 1), vec3(100.0f, 0.01f, 5.0f));
}

int	main(void)
{
	test_rotated_basis_nonuniform_scale();
	test_identity_basis_unit_scale();
	test_extreme_nonuniform_scale();
	return (UNIT_TEST_SUMMARY());
}
