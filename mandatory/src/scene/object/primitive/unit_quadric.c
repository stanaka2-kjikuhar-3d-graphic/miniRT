/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_quadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:12:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/05 22:55:37 by stanaka2         ###   ########.fr       */
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
*/
t_mat4	unit_quadric(enum e_primitive_type type)
{
	if (type == UNIT_SPHERE)
		return (mat4_diagonal(vec4(1.0f, 1.0f, 1.0f, -1.0f)));
	else
		return (mat4_diagonal(vec4(1.0f, 1.0f, 0.0f, -1.0f)));
}
