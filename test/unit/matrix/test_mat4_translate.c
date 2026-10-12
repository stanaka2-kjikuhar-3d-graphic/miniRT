#include "unit_test.h"

static void	test_places_offset_in_fourth_column(void)
{
	t_mat4	t;

	t = mat4_translate(vec3(3, -2, 5));
	CHECK(approx(t.m[0][3], 3.0f));
	CHECK(approx(t.m[1][3], -2.0f));
	CHECK(approx(t.m[2][3], 5.0f));
	CHECK(approx(t.m[0][0], 1.0f) && approx(t.m[1][1], 1.0f) \
		&& approx(t.m[2][2], 1.0f) && approx(t.m[3][3], 1.0f));
	CHECK(approx(t.m[3][0], 0.0f) && approx(t.m[3][1], 0.0f) \
		&& approx(t.m[3][2], 0.0f));
}

/* translating by zero is the identity matrix. */
static void	test_zero_is_identity(void)
{
	t_mat4	t;
	t_mat4	id;

	t = mat4_translate(vec3(0, 0, 0));
	id = mat4_identity();
	CHECK(mat4_eq(&t, &id));
}

/* negative offsets are placed as-is, not clamped or mirrored. */
static void	test_negative_offset(void)
{
	t_mat4	t;

	t = mat4_translate(vec3(-1, -2, -3));
	CHECK(approx(t.m[0][3], -1.0f) && approx(t.m[1][3], -2.0f) \
		&& approx(t.m[2][3], -3.0f));
}

int	main(void)
{
	test_places_offset_in_fourth_column();
	test_zero_is_identity();
	test_negative_offset();
	return (UNIT_TEST_SUMMARY());
}
