/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:42:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 14:02:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "vector.h"

/*
Rodrigues' rotation formula
k = normalize(axis);
v' = v * cosθ + (k×v) * sinθ + k * (k⋅v) * (1 − cosθ)
*/
t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis, float degree)
{
	float	radian;
	float	s;
	float	c;

	radian = degree * (float)DEG_TO_RAD;
	s = sinf(radian);
	c = cosf(radian);
	return (vec3_add(vec3_add(\
		vec3_scale(c, v), \
		vec3_scale(s, vec3_cross(axis, v))), \
		vec3_scale(vec3_dot(axis, v) * (1.0f - c), axis)) \
	);
}
