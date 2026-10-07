#include "unit_test.h"

/* direction: w = 0, so translation never applies. */
static void	test_ignores_translation(void)
{
	t_mat4	t;

	t = mat4_translate(vec3(3, -2, 5));
	CHECK(vec3_eq(mat4_transform_dir(&t, vec3(1, 0, 0)), vec3(1, 0, 0)));
}

/* but linear parts (rotation/scale) still apply. */
static void	test_scale_still_applies(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(2, 3, 4));
	CHECK(vec3_eq(mat4_transform_dir(&s, vec3(1, 1, 1)), vec3(2, 3, 4)));
}

/* rotation changes the direction, translation (mixed in via mat4_mul)
still has no effect on it. */
static void	test_rotation_applies_translation_does_not(void)
{
	t_mat4	r;
	t_mat4	t;
	t_mat4	m;

	r = mat4_rotate(vec3(0, 0, 1), 90.0f);
	t = mat4_translate(vec3(100, 100, 100));
	m = mat4_mul(&t, &r);
	CHECK(vec3_eq(mat4_transform_dir(&m, vec3(1, 0, 0)), vec3(0, 1, 0)));
}

/* a negative scale mirrors the direction (unlike a valid rotation, which
never flips a direction to point the opposite way). */
static void	test_negative_scale_mirrors(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(-1, 1, 1));
	CHECK(vec3_eq(mat4_transform_dir(&s, vec3(1, 0, 0)), vec3(-1, 0, 0)));
}

int	main(void)
{
	test_ignores_translation();
	test_scale_still_applies();
	test_rotation_applies_translation_does_not();
	test_negative_scale_mirrors();
	return (UNIT_TEST_SUMMARY());
}
