/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul_vec4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 23:24:27 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* result = m * v: each component is the dot of a matrix row with v. */
t_vec4	mat4_mul_vec4(t_mat4 m, t_vec4 v)
{
	t_vec4	result;

	result.x = vec4_dot(vec4(m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3]), v);
	result.y = vec4_dot(vec4(m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3]), v);
	result.z = vec4_dot(vec4(m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3]), v);
	result.w = vec4_dot(vec4(m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]), v);
	return (result);
}
