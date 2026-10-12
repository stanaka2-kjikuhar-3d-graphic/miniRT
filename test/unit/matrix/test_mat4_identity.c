#include "unit_test.h"

int	main(void)
{
	t_mat4	id;
	int		row;
	int		col;

	id = mat4_identity();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (row == col)
				CHECK(approx(id.m[row][col], 1.0f));
			else
				CHECK(approx(id.m[row][col], 0.0f));
			++col;
		}
		++row;
	}
	return (UNIT_TEST_SUMMARY());
}
