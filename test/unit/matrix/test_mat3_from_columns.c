#include "unit_test.h"

/* x, y, z go in as columns 0, 1, 2. */
static void	test_places_vectors_as_columns(void)
{
	t_mat3	m;

	m = mat3_from_columns(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9));
	CHECK(approx(m.m[0][0], 1.0f) && approx(m.m[1][0], 2.0f) \
		&& approx(m.m[2][0], 3.0f));
	CHECK(approx(m.m[0][1], 4.0f) && approx(m.m[1][1], 5.0f) \
		&& approx(m.m[2][1], 6.0f));
	CHECK(approx(m.m[0][2], 7.0f) && approx(m.m[1][2], 8.0f) \
		&& approx(m.m[2][2], 9.0f));
}

/* the standard basis vectors give the 3x3 identity. */
static void	test_standard_basis_gives_identity(void)
{
	t_mat3	m;
	int		row;
	int		col;

	m = mat3_from_columns(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1));
	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (row == col)
				CHECK(approx(m.m[row][col], 1.0f));
			else
				CHECK(approx(m.m[row][col], 0.0f));
			++col;
		}
		++row;
	}
}

/* the columns do not have to be orthonormal (or even independent):
the function is a plain layout helper, not a basis validator. */
static void	test_does_not_require_orthonormal_columns(void)
{
	t_mat3	m;

	m = mat3_from_columns(vec3(1, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0));
	CHECK(approx(m.m[0][0], 1.0f) && approx(m.m[0][1], 1.0f) \
		&& approx(m.m[0][2], 0.0f));
}

int	main(void)
{
	test_places_vectors_as_columns();
	test_standard_basis_gives_identity();
	test_does_not_require_orthonormal_columns();
	return (UNIT_TEST_SUMMARY());
}
