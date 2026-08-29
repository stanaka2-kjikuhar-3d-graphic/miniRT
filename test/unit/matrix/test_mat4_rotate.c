#include "unit_test.h"

/*
90 deg around Z: columns become the rotated basis vectors
(x->y, y->-x, z->z), i.e. Rodrigues with k = axis.
*/
static void	test_ninety_degrees_around_z(void)
{
	t_mat4	r;

	r = mat4_rotate(vec3(0, 0, 1), 90.0f);
	CHECK(approx(r.m[0][0], 0.0f) && approx(r.m[1][0], 1.0f) \
		&& approx(r.m[2][0], 0.0f));
	CHECK(approx(r.m[0][1], -1.0f) && approx(r.m[1][1], 0.0f) \
		&& approx(r.m[2][1], 0.0f));
	CHECK(approx(r.m[0][2], 0.0f) && approx(r.m[1][2], 0.0f) \
		&& approx(r.m[2][2], 1.0f));
	CHECK(approx(r.m[3][3], 1.0f));
}

/* 0 degrees is the identity, whatever the axis. */
static void	test_zero_degrees_is_identity(void)
{
	t_mat4	r;
	t_mat4	id;

	r = mat4_rotate(vec3(1, 1, 1), 0.0f);
	id = mat4_identity();
	CHECK(mat4_eq(&r, &id));
}

/* 180 degrees around Z flips X and Y, leaves Z untouched. */
static void	test_hundred_eighty_degrees(void)
{
	t_mat4	r;

	r = mat4_rotate(vec3(0, 0, 1), 180.0f);
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(1, 0, 0)), vec3(-1, 0, 0)));
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(0, 1, 0)), vec3(0, -1, 0)));
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(0, 0, 1)), vec3(0, 0, 1)));
}

/* rotating around X takes Y towards Z (right-hand rule). */
static void	test_ninety_degrees_around_x(void)
{
	t_mat4	r;

	r = mat4_rotate(vec3(1, 0, 0), 90.0f);
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(0, 1, 0)), vec3(0, 0, 1)));
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(1, 0, 0)), vec3(1, 0, 0)));
}

/* a negative angle rotates the other way. */
static void	test_negative_angle(void)
{
	t_mat4	r;

	r = mat4_rotate(vec3(0, 0, 1), -90.0f);
	CHECK(vec3_eq(mat4_transform_dir(&r, vec3(1, 0, 0)), vec3(0, -1, 0)));
}

int	main(void)
{
	test_ninety_degrees_around_z();
	test_zero_degrees_is_identity();
	test_hundred_eighty_degrees();
	test_ninety_degrees_around_x();
	test_negative_angle();
	return (UNIT_TEST_SUMMARY());
}
