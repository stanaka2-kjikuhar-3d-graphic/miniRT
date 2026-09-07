/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul_vec4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 18:48:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* result = m * v: each component is the dot of a matrix row with v. */
t_vec4	mat4_mul_vec4(t_mat4 const *m, t_vec4 v)
{
	return ((t_vec4){
		.x = vec4_dot(m->row[0], v), \
		.y = vec4_dot(m->row[1], v), \
		.z = vec4_dot(m->row[2], v), \
		.w = vec4_dot(m->row[3], v) \
	});
}
