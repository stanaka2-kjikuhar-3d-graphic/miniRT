/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:43:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 18:50:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include <assert.h>
# include <stddef.h>

# include "vector.h"

/*
a basis vector index. rows are world axes (e_axis), columns are the
local basis vectors, so m[Y_AXIS][U_AXIS] is u.y.
*/
enum e_basis
{
	U_AXIS,
	V_AXIS,
	W_AXIS,
};

/*
t_mat3: basis vectors are COLUMNS.

              U_AXIS   V_AXIS   W_AXIS
           +----------------------------+
    X_AXIS |   u.x      v.x      w.x    |
    Y_AXIS |   u.y      v.y      w.y    |
    Z_AXIS |   u.z      v.z      w.z    |
           +----------------------------+

  local -> world :  M * p
  world -> local :  transpose(M) * p   (orthonormal basis only)

  row[] and x, y, z name ROWS, not the basis vectors. a column is not
  contiguous, so a function that builds one writes m[][] by hand.
*/
typedef struct s_mat3
{
	union
	{
		float	m[3][3];
		t_vec3	row[3];
		struct
		{
			t_vec3	x;
			t_vec3	y;
			t_vec3	z;
		};
	};
}	t_mat3;

# define MAT3_ASSERTION "Error\nmemory alignment of t_mat3."

static_assert(sizeof(float [3][3]) == sizeof(t_vec3 [3]), MAT3_ASSERTION);

static_assert(offsetof(t_mat3, x) == 0, MAT3_ASSERTION " x != m[0]");
static_assert(offsetof(t_mat3, y) == sizeof(t_vec3), \
				MAT3_ASSERTION " y != m[1]");
static_assert(offsetof(t_mat3, z) == 2 * sizeof(t_vec3), \
				MAT3_ASSERTION " z != m[2]");

typedef struct s_mat4
{
	union
	{
		float	m[4][4];
		t_vec4	row[4];
		struct
		{
			t_vec4	x;
			t_vec4	y;
			t_vec4	z;
			t_vec4	w;
		};
	};
}	t_mat4;

# define MAT4_ASSERTION "Error\nmemory alignment of t_mat4."

static_assert(sizeof(float [4][4]) == sizeof(t_vec4 [4]), MAT4_ASSERTION);

static_assert(offsetof(t_mat4, x) == 0, MAT4_ASSERTION " x != m[0]");
static_assert(offsetof(t_mat4, y) == sizeof(t_vec4), \
				MAT4_ASSERTION " y != m[1]");
static_assert(offsetof(t_mat4, z) == 2 * sizeof(t_vec4), \
				MAT4_ASSERTION " z != m[2]");
static_assert(offsetof(t_mat4, w) == 3 * sizeof(t_vec4), \
				MAT4_ASSERTION " w != m[3]");

t_mat4	mat4_identity(void);
t_mat4	mat4_mul(t_mat4 const *a, t_mat4 const *b);
t_mat4	mat4_transpose(t_mat4 const *m);
t_mat4	mat4_inverse(t_mat4 const *m);
t_vec4	mat4_mul_vec4(t_mat4 const *m, t_vec4 v);
t_vec3	mat4_transform_point(t_mat4 const *m, t_vec3 p);
t_vec3	mat4_transform_dir(t_mat4 const *m, t_vec3 v);

t_mat4	mat4_translate(t_vec3 t);
t_mat4	mat4_scale(t_vec3 s);
t_mat4	mat4_rotate(t_vec3 axis, float degree);
t_mat4	mat4_basis(t_mat3 const *basis, t_vec3 origin);
t_mat4	mat4_local_to_world(\
			t_mat3 const *basis, t_vec3 origin, t_vec3 scale);
t_mat4	mat4_world_to_local(\
			t_mat3 const *basis, t_vec3 origin, t_vec3 scale);
bool	mat4_is_valid_scale(t_vec3 scale);

t_mat3	mat3_from_mat4(t_mat4 const *m);
t_vec3	mat3_mul_t_vec3(t_mat3 const *m, t_vec3 v);
t_vec3	mat3_mul_vec3(t_mat3 const *m, t_vec3 v);
t_mat3	mat3_from_columns(t_vec3 u, t_vec3 v, t_vec3 w);

float	mat4_minor(t_mat4 const *m, int row, int col);
float	mat4_cofactor(t_mat4 const *m, int row, int col);
float	mat4_det(t_mat4 const *m);

#endif
