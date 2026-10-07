#include "unit_test.h"

/* point: w = 1, so it receives translation. */
static void	test_receives_translation(void)
{
	t_mat4	t;

	t = mat4_translate(vec3(3, -2, 5));
	CHECK(vec3_eq(mat4_transform_point(&t, vec3(0, 0, 0)), vec3(3, -2, 5)));
}

/* order of composition: translate * scale applies scale first, then moves. */
static void	test_scale_then_translate(void)
{
	t_mat4	t;
	t_mat4	s;
	t_mat4	m;

	t = mat4_translate(vec3(5, 6, 7));
	s = mat4_scale(vec3(2, 3, 4));
	m = mat4_mul(&t, &s);
	CHECK(vec3_eq(mat4_transform_point(&m, vec3(1, 1, 1)), vec3(7, 9, 11)));
}

/* the reverse order (scale * translate) is a different matrix: it
translates first, in the *unscaled* local space, then scales the result. */
static void	test_order_matters(void)
{
	t_mat4	t;
	t_mat4	s;
	t_mat4	m;

	t = mat4_translate(vec3(5, 6, 7));
	s = mat4_scale(vec3(2, 3, 4));
	m = mat4_mul(&s, &t);
	CHECK(vec3_eq(mat4_transform_point(&m, vec3(1, 1, 1)), vec3(12, 21, 32)));
}

/* negative coordinates are transformed the same way as positive ones. */
static void	test_negative_coordinates(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(2, 2, 2));
	CHECK(vec3_eq(\
		mat4_transform_point(&s, vec3(-1, -2, -3)), vec3(-2, -4, -6)));
}

int	main(void)
{
	test_receives_translation();
	test_scale_then_translate();
	test_order_matters();
	test_negative_coordinates();
	return (UNIT_TEST_SUMMARY());
}
