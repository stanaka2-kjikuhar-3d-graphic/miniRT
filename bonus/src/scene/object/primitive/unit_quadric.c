/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_quadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:12:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/31 21:00:21 by stanaka2         ###   ########.fr       */
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

	if (type == UNIT_SPHERE)
		return (mat4_diagonal(vec4(1.0f, 1.0f, 1.0f, -1.0f)));
	else if (type == UNIT_CYLINDER)
		return (mat4_diagonal(vec4(1.0f, 1.0f, 0.0f, -1.0f)));
	else if (type == UNIT_CONE)
		return (mat4_diagonal(vec4(1.0f, 1.0f, -1.0f, 0.0f)));
	else if (type == UNIT_HYPERBOLOID)
		return (mat4_diagonal(vec4(1.0f, 1.0f, -1.0f, -1.0f)));
	else
	{
		q = mat4_diagonal(vec4(1.0f, 1.0f, 0.0f, 0.0f));
		q.m[2][3] = -0.5f;
		q.m[3][2] = -0.5f;
		return (q);
	}
}
