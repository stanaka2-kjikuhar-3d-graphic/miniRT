/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_quadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:12:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 14:40:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

/*
Q of the unit form, as p^T Q p = 0.
    UNIT_SPHERE        diag( 1, 1,  1, -1)
    UNIT_CYLINDER      diag( 1, 1,  0, -1)
    UNIT_CONE          diag( 1, 1, -1,  0)
    UNIT_HYPERBOLOID   diag( 1, 1, -1, -1)
    UNIT_PARABOLOID    diag( 1, 1,  0,  0), m[2][3] = m[3][2] = -1/2
*/
t_mat4	unit_quadric(enum e_primitive_type type)
{
	t_mat4	q;

	q = mat4_identity();
	q.m[3][3] = -1.0f;
	if (type == UNIT_CYLINDER)
		q.m[2][2] = 0.0f;
	else if (type == UNIT_CONE)
	{
		q.m[2][2] = -1.0f;
		q.m[3][3] = 0.0f;
	}
	else if (type == UNIT_HYPERBOLOID)
		q.m[2][2] = -1.0f;
	else if (type == UNIT_PARABOLOID)
	{
		q.m[2][2] = 0.0f;
		q.m[3][3] = 0.0f;
		q.m[2][3] = -0.5f;
		q.m[3][2] = -0.5f;
	}
	return (q);
}
