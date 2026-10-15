/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_mul_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:18:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 17:28:20 by stanaka2         ###   ########.fr       */
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
	return ((t_vec3){
		.x = vec3_dot(m->row[0], v), \
		.y = vec3_dot(m->row[1], v), \
		.z = vec3_dot(m->row[2], v)
	});
}
