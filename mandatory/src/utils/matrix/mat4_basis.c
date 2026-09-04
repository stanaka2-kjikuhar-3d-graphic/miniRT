/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_basis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:50 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 18:50:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* local->world M: upper 3x3 = basis, 4th column = origin. */
t_mat4	mat4_basis(t_mat3 const *basis, t_vec3 origin)
{
	return ((t_mat4){.m = {\
		{basis->m[0][0], basis->m[0][1], basis->m[0][2], origin.x}, \
		{basis->m[1][0], basis->m[1][1], basis->m[1][2], origin.y}, \
		{basis->m[2][0], basis->m[2][1], basis->m[2][2], origin.z}, \
		{0.0f, 0.0f, 0.0f, 1.0f} \
	}});
}
