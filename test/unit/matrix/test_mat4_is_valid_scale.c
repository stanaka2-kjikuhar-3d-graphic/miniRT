#include "unit_test.h"

# define EPSILON_TEST 0.000001f

static void	test_typical_scales(void)
{
	CHECK(mat4_is_valid_scale(vec3(1, 1, 1)) == true);
	CHECK(mat4_is_valid_scale(vec3(-2, 3, 4)) == true);
}

static void	test_zero_component_is_invalid(void)
{
	CHECK(mat4_is_valid_scale(vec3(0, 1, 1)) == false);
	CHECK(mat4_is_valid_scale(vec3(1, 0, 1)) == false);
	CHECK(mat4_is_valid_scale(vec3(1, 1, 0)) == false);
}

/* the check is EPSILON <= |s|, so exactly EPSILON passes, and anything
strictly below it (however small the margin) fails. */
static void	test_epsilon_boundary(void)
{
	CHECK(mat4_is_valid_scale(vec3(EPSILON_TEST, 1, 1)) == true);
	CHECK(mat4_is_valid_scale(vec3(EPSILON_TEST / 2.0f, 1, 1)) == false);
}

/* the sign of the scale is irrelevant: only the magnitude matters. */
static void	test_negative_near_zero(void)
{
	CHECK(mat4_is_valid_scale(vec3(-EPSILON_TEST / 2.0f, 1, 1)) == false);
	CHECK(mat4_is_valid_scale(vec3(-1, -1, -1)) == true);
}

int	main(void)
{
	test_typical_scales();
	test_zero_component_is_invalid();
	test_epsilon_boundary();
	test_negative_near_zero();
	return (UNIT_TEST_SUMMARY());
}
