/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_world_to_local.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 03:02:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 19:11:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static void	set_rotation_scale(\
				t_mat4 *m, t_mat3 const *basis, t_vec3 scale);
static void	set_translation(t_mat4 *m, t_vec3 origin);

/*
M^-1 of mat4_local_to_world, in closed form.

    M    = translate(origin) * basis * scale(s)
    M^-1 = scale(1/s) * transpose(basis) * translate(-origin)

  the basis is orthonormal, so its inverse is its transpose and no
  general inversion is needed. mat4_inverse would answer the same
  matrix, but only to a few digits less: that error is amplified by
  1 / cos when a ray grazes the surface, so the closed form is used.

  callers must reject a degenerate scale first (see mat4_is_valid_scale).
*/
t_mat4	mat4_world_to_local(t_mat3 const *basis, t_vec3 origin, t_vec3 scale)
{
	t_mat4	result;

	result = mat4_identity();
	set_rotation_scale(&result, basis, scale);
	set_translation(&result, origin);
	return (result);
}

/* row i of the 3x3 block is basis column i divided by that axis' scale. */
static void	set_rotation_scale(t_mat4 *m, t_mat3 const *basis, t_vec3 scale)
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			m->m[row][col] = basis->m[col][row] / scale.e[row];
			++col;
		}
		++row;
	}
}

/* the 4th column carries -origin, already rotated and scaled. */
static void	set_translation(t_mat4 *m, t_vec3 origin)
{
	t_vec4	vec4_origin;
	int		i;

	vec4_origin = vec4(origin.x, origin.y, origin.z, 0.0f);
	i = 0;
	while (i < 3)
	{
		m->row[i].w = -(vec4_dot(m->row[i], vec4_origin));
		++i;
	}
}
