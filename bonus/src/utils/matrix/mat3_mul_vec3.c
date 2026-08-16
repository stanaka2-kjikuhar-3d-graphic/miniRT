/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_mul_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:18:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 20:28:07 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

/*
m * v: every component is one ROW of m dotted with v.

           +-------------------+   +-----+     +-----+
    row 0  |  a     b     c    |   | v.x |     | r.x |
    row 1  |  d     e     f    | * | v.y |  =  | r.y |
    row 2  |  g     h     i    |   | v.z |     | r.z |
           +-------------------+   +-----+     +-----+

  with T, B, N in the columns, this takes tangent space to world.
*/
t_vec3	mat3_mul_vec3(t_mat3 const *m, t_vec3 v)
{
	t_vec3	result;

	result.x = m->m[0][0] * v.x + m->m[0][1] * v.y + m->m[0][2] * v.z;
	result.y = m->m[1][0] * v.x + m->m[1][1] * v.y + m->m[1][2] * v.z;
	result.z = m->m[2][0] * v.x + m->m[2][1] * v.y + m->m[2][2] * v.z;
	return (result);
}
