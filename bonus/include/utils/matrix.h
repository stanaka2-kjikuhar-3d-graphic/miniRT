/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:43:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 22:19:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

typedef struct s_mat3
{
	float	m[3][3];
}	t_mat3;

typedef struct s_mat4
{
	float	m[4][4];
}	t_mat4;

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

t_mat3	mat3_from_mat4(t_mat4 const *m);

float	mat4_minor(t_mat4 const *m, int row, int col);
float	mat4_cofactor(t_mat4 const *m, int row, int col);
float	mat4_det(t_mat4 const *m);

#endif
