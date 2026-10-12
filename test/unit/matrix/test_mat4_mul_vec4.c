#include "unit_test.h"

static void	test_identity_leaves_vec4_unchanged(void)
{
	t_mat4	id;
	t_vec4	v;

	id = mat4_identity();
	v = vec4(1, 2, 3, 1);
	CHECK(vec4_eq(mat4_mul_vec4(&id, v), v));
}

/* translation only shows up when w = 1 (point), never when w = 0 (dir). */
static void	test_translation_scaled_by_w(void)
{
	t_mat4	t;

	t = mat4_translate(vec3(1, 2, 3));
	CHECK(vec4_eq(mat4_mul_vec4(&t, vec4(0, 0, 0, 1)), vec4(1, 2, 3, 1)));
	CHECK(vec4_eq(mat4_mul_vec4(&t, vec4(0, 0, 0, 0)), vec4(0, 0, 0, 0)));
}

/* every component of a scale matrix scales independently. */
static void	test_scale(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(2, 3, 4));
	CHECK(vec4_eq(mat4_mul_vec4(&s, vec4(1, 1, 1, 1)), vec4(2, 3, 4, 1)));
}

/* a general matrix (rotate then translate) mixes all rows: each result
component is a dot of a matrix row with the full input vector. */
static void	test_general_matrix(void)
{
	t_mat4	r;
	t_mat4	t;
	t_mat4	m;

	r = mat4_rotate(vec3(0, 0, 1), 90.0f);
	t = mat4_translate(vec3(5, 0, 0));
	m = mat4_mul(&t, &r);
	CHECK(vec4_eq(mat4_mul_vec4(&m, vec4(1, 0, 0, 1)), vec4(5, 1, 0, 1)));
}

int	main(void)
{
	test_identity_leaves_vec4_unchanged();
	test_translation_scaled_by_w();
	test_scale();
	test_general_matrix();
	return (UNIT_TEST_SUMMARY());
}
