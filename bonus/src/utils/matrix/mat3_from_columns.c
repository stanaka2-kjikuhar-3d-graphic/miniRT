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

              U_AXIS   V_AXIS   W_AXIS
           +--------------------------+
    X_AXIS |   u.x      v.x      w.x  |
    Y_AXIS |   u.y      v.y      w.y  |
    Z_AXIS |   u.z      v.z      w.z  |
           +--------------------------+
*/
t_mat3	mat3_from_columns(t_vec3 u, t_vec3 v, t_vec3 w)
{
	return ((t_mat3){.m = {\
		{u.x, v.x, w.x}, \
		{u.y, v.y, w.y}, \
		{u.z, v.z, w.z} \
	}});
}
