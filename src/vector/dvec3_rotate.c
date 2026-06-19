/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:42:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:05:35 by stanaka2         ###   ########.fr       */
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
t_dvec3	dvec3_rotate(t_dvec3 v, t_dvec3 axis, double degree)
{
	double	radian;
	double	s;
	double	c;

	radian = degree * DEG_TO_RAD;
	s = sin(radian);
	c = cos(radian);
	return (dvec3_add(dvec3_add(\
		dvec3_scale(c, v), \
		dvec3_scale(s, dvec3_cross(axis, v))), \
		dvec3_scale(dvec3_dot(axis, v) * (1.0 - c), axis)) \
	);
}
