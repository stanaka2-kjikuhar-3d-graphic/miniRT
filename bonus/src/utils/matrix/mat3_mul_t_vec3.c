/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_mul_t_vec3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:36:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 18:46:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

/* transpose(m) * v, as a dot with each column. See docs/primitive_normal.md. */
t_vec3	mat3_mul_t_vec3(t_mat3 const *m, t_vec3 v)
{
	t_vec3	result;

	result.x = m->m[0][0] * v.x + m->m[1][0] * v.y + m->m[2][0] * v.z;
	result.y = m->m[0][1] * v.x + m->m[1][1] * v.y + m->m[2][1] * v.z;
	result.z = m->m[0][2] * v.x + m->m[1][2] * v.y + m->m[2][2] * v.z;
	return (result);
}
