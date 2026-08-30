/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_mul_t_vec3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:36:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 17:25:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

/* transpose(m) * v, as a dot with each column. See docs/primitive_normal.md. */
t_vec3	mat3_mul_t_vec3(t_mat3 const *m, t_vec3 v)
{
	return ((t_vec3){
		.x = vec3_dot(vec3(m->m[0][0], m->m[1][0], m->m[2][0]), v),
		.y = vec3_dot(vec3(m->m[0][1], m->m[1][1], m->m[2][1]), v),
		.z = vec3_dot(vec3(m->m[0][2], m->m[1][2], m->m[2][2]), v)
	});
}
