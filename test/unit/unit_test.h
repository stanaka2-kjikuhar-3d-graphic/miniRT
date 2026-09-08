/*
 * Shared helpers for the matrix unit tests.
 *
 * Each test_*.c file tests exactly one function and has its own main().
 * This header is included by every one of them; the globals below end up
 * as one private copy per test binary (no ODR issue, since each file is
 * compiled into its own executable by run_unit_tests.sh).
 */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <math.h>
# include <stdio.h>

# include "matrix.h"
# include "vector.h"

# define EPS_TEST 1e-4f

static int	g_pass;
static int	g_fail;

# define CHECK(cond) do { \
		if (cond) \
			++g_pass; \
		else \
		{ \
			++g_fail; \
			printf("  FAIL: %s (%s:%d)\n", #cond, __FILE__, __LINE__); \
		} \
	} while (0)

# define UNIT_TEST_SUMMARY() (\
		printf("%d passed, %d failed\n", g_pass, g_fail), \
		g_fail != 0)

static inline int	approx(float a, float b)
{
	return (fabsf(a - b) < EPS_TEST);
}

static inline int	vec3_eq(t_vec3 a, t_vec3 b)
{
	return (approx(a.x, b.x) && approx(a.y, b.y) && approx(a.z, b.z));
}

static inline int	vec4_eq(t_vec4 a, t_vec4 b)
{
	return (approx(a.x, b.x) && approx(a.y, b.y) \
		&& approx(a.z, b.z) && approx(a.w, b.w));
}

static inline int	mat4_eq(t_mat4 const *a, t_mat4 const *b)
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (!approx(a->m[row][col], b->m[row][col]))
				return (0);
			++col;
		}
		++row;
	}
	return (1);
}

static inline int	mat3_eq(t_mat3 const *a, t_mat3 const *b)
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (!approx(a->m[row][col], b->m[row][col]))
				return (0);
			++col;
		}
		++row;
	}
	return (1);
}

#endif
