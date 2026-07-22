/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_uv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:37:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/21 21:35:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_cylinder_uv(t_cylinder const *cylinder, t_vec3 point)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	h;
	t_vec3	normal;
	float	phi;

	to_point = vec3_sub(point, cylinder->center);
	h = vec3_dot(to_point, cylinder->onb.w);
	normal = vec3_normalize(vec3_sub(to_point, vec3_scale(h, cylinder->onb.w)));
	phi = atan2f(vec3_dot(normal, cylinder->onb.v), \
					vec3_dot(normal, cylinder->onb.u));
	uv.u = (float)((phi + M_PI) / (2.0f * M_PI));
	uv.v = 0.5f - h / (cylinder->half_height * 2.0f);
	return (uv);
}
