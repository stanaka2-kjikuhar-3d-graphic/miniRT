/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:43:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/31 21:00:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include <assert.h>

# include "vector.h"

typedef struct s_mat3
{
	union
	{
		float	m[3][3];
		t_vec3	row[3];
	};
}	t_mat3;

# define MAT3_ASSERTION "Error\nmemory alignment of t_mat3."

static_assert(sizeof(float [3][3]) == sizeof(t_vec3 [3]), MAT3_ASSERTION);

typedef struct s_mat4
{
	union
	{
		float	m[4][4];
		t_vec4	row[4];
	};
}	t_mat4;

# define MAT4_ASSERTION "Error\nmemory alignment of t_mat4."

static_assert(sizeof(float [4][4]) == sizeof(t_vec4 [4]), MAT4_ASSERTION);

t_mat4	mat4_identity(void);
t_mat4	mat4_diagonal(t_vec4 diag);
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
t_vec3	mat3_mul_transposed(t_mat3 const *m, t_vec3 v);
t_vec3	mat3_mul_vec3(t_mat3 const *m, t_vec3 v);
t_mat3	mat3_from_columns(t_vec3 u, t_vec3 v, t_vec3 w);

float	mat4_minor(t_mat4 const *m, int row, int col);
float	mat4_cofactor(t_mat4 const *m, int row, int col);
float	mat4_det(t_mat4 const *m);

#endif
