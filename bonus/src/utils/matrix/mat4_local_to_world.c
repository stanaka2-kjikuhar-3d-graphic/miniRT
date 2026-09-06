/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_local_to_world.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:31:04 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 18:47:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
M = translate(origin) * basis * scale(s)

             u * s.x   v * s.y   w * s.z    origin
           +----------------------------------------+
    row 0  | u.x*s.x   v.x*s.y   w.x*s.z   origin.x |
    row 1  | u.y*s.x   v.y*s.y   w.y*s.z   origin.y |
    row 2  | u.z*s.x   v.z*s.y   w.z*s.z   origin.z |
    row 3  |    0         0         0         1     |
           +----------------------------------------+

  each basis column is scaled, the 4th column carries the origin.
*/
t_mat4	mat4_local_to_world(t_mat3 const *basis, t_vec3 origin, t_vec3 scale)
{
	t_mat4	result;
	int		row;
	int		col;

	result = mat4_basis(basis, origin);
	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			result.m[row][col] *= scale.e[col];
			++col;
		}
		++row;
	}
	return (result);
}
