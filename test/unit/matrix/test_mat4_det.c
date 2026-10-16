#include "unit_test.h"

static void	test_diagonal(void)
{
	t_mat4	m;

	m = mat4_identity();
	CHECK(approx(mat4_det(&m), 1.0f));
	m.m[0][0] = 1;
	m.m[1][1] = 2;
	m.m[2][2] = 3;
	m.m[3][3] = 4;
	CHECK(approx(mat4_det(&m), 24.0f));
}

/* det(translate * rotate * scale) = det(rotate) * det(scale) = 1 * s.x*s.y*s.z
(a proper rotation has determinant 1, translation does not scale volume). */
static void	test_rigid_transform(void)
{
	t_mat4	rot;
	t_mat3	basis;
	t_mat4	m;

	rot = mat4_rotate(vec3(0, 0, 1), 90.0f);
	basis = mat3_from_mat4(&rot);
	m = mat4_local_to_world(&basis, vec3(5, -2, 7), vec3(2, 3, 4));
	CHECK(approx(mat4_det(&m), 24.0f));
}

/* two identical rows make the matrix singular: det == 0. */
static void	test_singular_matrix_is_zero(void)
{
	t_mat4	m;

	m = (t_mat4){.m = { \
		{1, 2, 3, 4}, \
		{1, 2, 3, 4}, \
		{0, 0, 1, 0}, \
		{0, 0, 0, 1}}};
	CHECK(approx(mat4_det(&m), 0.0f));
}

/* det is multiplicative: det(a * b) == det(a) * det(b). */
static void	test_multiplicative(void)
{
	t_mat4	a;
	t_mat4	b;
	t_mat4	product;

	a = mat4_scale(vec3(2, 3, 4));
	b = mat4_rotate(vec3(0, 0, 1), 30.0f);
	product = mat4_mul(&a, &b);
	CHECK(approx(mat4_det(&product), mat4_det(&a) * mat4_det(&b)));
}

int	main(void)
{
	test_diagonal();
	test_rigid_transform();
	test_singular_matrix_is_zero();
	test_multiplicative();
	return (UNIT_TEST_SUMMARY());
}
