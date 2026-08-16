/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_from_columns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:19:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 20:28:22 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

/*
basis vectors go in as columns.

              x        y        z
           +--------------------------+
    row 0  |  x.x      y.x      z.x   |
    row 1  |  x.y      y.y      z.y   |
    row 2  |  x.z      y.z      z.z   |
           +--------------------------+
*/
t_mat3	mat3_from_columns(t_vec3 x, t_vec3 y, t_vec3 z)
{
	t_mat3	m;

	m.m[0][X_AXIS] = x.x;
	m.m[1][X_AXIS] = x.y;
	m.m[2][X_AXIS] = x.z;
	m.m[0][Y_AXIS] = y.x;
	m.m[1][Y_AXIS] = y.y;
	m.m[2][Y_AXIS] = y.z;
	m.m[0][Z_AXIS] = z.x;
	m.m[1][Z_AXIS] = z.y;
	m.m[2][Z_AXIS] = z.z;
	return (m);
}
