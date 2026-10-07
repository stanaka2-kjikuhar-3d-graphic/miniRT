#include "unit_test.h"

/* a * identity == a, identity * a == a */
static void	test_identity_is_noop(void)
{
	t_mat4	a;
	t_mat4	id;
	t_mat4	result;

	a = mat4_basis(&(t_mat3){.m = { \
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, vec3(10, 11, 12));
	id = mat4_identity();
	result = mat4_mul(&a, &id);
	CHECK(mat4_eq(&result, &a));
	result = mat4_mul(&id, &a);
	CHECK(mat4_eq(&result, &a));
}

/* result[row][col] = sum_k a[row][k] * b[k][col], checked by hand. */
static void	test_known_product(void)
{
	t_mat4	t;
	t_mat4	s;
	t_mat4	m;
	t_mat4	expected;

	t = mat4_translate(vec3(5, 6, 7));
	s = mat4_scale(vec3(2, 3, 4));
	m = mat4_mul(&t, &s);
	expected = mat4_identity();
	expected.m[0][0] = 2;
	expected.m[1][1] = 3;
	expected.m[2][2] = 4;
	expected.m[0][3] = 5;
	expected.m[1][3] = 6;
	expected.m[2][3] = 7;
	CHECK(mat4_eq(&m, &expected));
}

/* matrix mul is associative: (a*b)*c == a*(b*c). */
static void	test_associative(void)
{
	t_mat4	a;
	t_mat4	b;
	t_mat4	c;
	t_mat4	left;
	t_mat4	right;
	t_mat4	tmp;

	a = mat4_translate(vec3(1, 2, 3));
	b = mat4_scale(vec3(2, 3, 4));
	c = mat4_rotate(vec3(0, 0, 1), 45.0f);
	tmp = mat4_mul(&a, &b);
	left = mat4_mul(&tmp, &c);
	tmp = mat4_mul(&b, &c);
	right = mat4_mul(&a, &tmp);
	CHECK(mat4_eq(&left, &right));
}

/* the all-zero matrix annihilates anything it multiplies. */
static void	test_zero_matrix_annihilates(void)
{
	t_mat4	zero;
	t_mat4	a;
	t_mat4	result;

	zero = (t_mat4){0};
	a = mat4_basis(&(t_mat3){.m = { \
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}}, vec3(10, 11, 12));
	result = mat4_mul(&zero, &a);
	CHECK(mat4_eq(&result, &zero));
}

int	main(void)
{
	test_identity_is_noop();
	test_known_product();
	test_associative();
	test_zero_matrix_annihilates();
	return (UNIT_TEST_SUMMARY());
}
