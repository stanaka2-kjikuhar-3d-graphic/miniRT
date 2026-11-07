/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:39:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

/* Point (w = 1): projected back with the w division. See docs/matrix.md. */
t_vec3	mat4_transform_point(t_mat4 const *m, t_vec3 p)
{
	return (vec4_to_vec3(mat4_mul_vec4(m, vec4_from_point(p))));
}
