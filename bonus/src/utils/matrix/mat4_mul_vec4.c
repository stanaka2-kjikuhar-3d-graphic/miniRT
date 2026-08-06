/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul_vec4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:36 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* result = m * v: each component is the dot of a matrix row with v. */
t_vec4	mat4_mul_vec4(t_mat4 const *m, t_vec4 v)
{
	t_vec4	result;

	result.x = m->m[0][0] * v.x + m->m[0][1] * v.y \
				+ m->m[0][2] * v.z + m->m[0][3] * v.w;
	result.y = m->m[1][0] * v.x + m->m[1][1] * v.y \
				+ m->m[1][2] * v.z + m->m[1][3] * v.w;
	result.z = m->m[2][0] * v.x + m->m[2][1] * v.y \
				+ m->m[2][2] * v.z + m->m[2][3] * v.w;
	result.w = m->m[3][0] * v.x + m->m[3][1] * v.y \
				+ m->m[3][2] * v.z + m->m[3][3] * v.w;
	return (result);
}
