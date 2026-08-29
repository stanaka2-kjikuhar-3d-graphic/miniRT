#include "unit_test.h"

static void	test_places_scale_on_diagonal(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(2, 3, 4));
	CHECK(approx(s.m[0][0], 2.0f));
	CHECK(approx(s.m[1][1], 3.0f));
	CHECK(approx(s.m[2][2], 4.0f));
	CHECK(approx(s.m[3][3], 1.0f));
	CHECK(approx(s.m[0][1], 0.0f) && approx(s.m[0][3], 0.0f) \
		&& approx(s.m[1][0], 0.0f) && approx(s.m[2][3], 0.0f));
}

/* scale of (1, 1, 1) is the identity matrix. */
static void	test_uniform_one_is_identity(void)
{
	t_mat4	s;
	t_mat4	id;

	s = mat4_scale(vec3(1, 1, 1));
	id = mat4_identity();
	CHECK(mat4_eq(&s, &id));
}

/* a negative component flips that axis instead of shrinking it. */
static void	test_negative_scale_flips_axis(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(-1, 1, 1));
	CHECK(approx(s.m[0][0], -1.0f));
}

/* fractional scale shrinks. */
static void	test_fractional_scale(void)
{
	t_mat4	s;

	s = mat4_scale(vec3(0.5f, 0.25f, 0.1f));
	CHECK(approx(s.m[0][0], 0.5f) && approx(s.m[1][1], 0.25f) \
		&& approx(s.m[2][2], 0.1f));
}

int	main(void)
{
	test_places_scale_on_diagonal();
	test_uniform_one_is_identity();
	test_negative_scale_flips_axis();
	test_fractional_scale();
	return (UNIT_TEST_SUMMARY());
}
