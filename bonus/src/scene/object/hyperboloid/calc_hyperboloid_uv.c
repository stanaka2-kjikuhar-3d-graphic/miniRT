/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_uv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:36:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 21:34:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_hyperboloid_uv(t_hyperboloid const *hyperboloid, t_vec3 point)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	h;
	t_vec3	normal;
	float	phi;

	to_point = vec3_sub(point, hyperboloid->center);
	h = vec3_dot(to_point, hyperboloid->dir);
	normal = vec3_normalize(\
			vec3_sub(to_point, vec3_scale(h, hyperboloid->dir)));
	phi = atan2f(vec3_dot(normal, hyperboloid->onb.v), \
					vec3_dot(normal, hyperboloid->onb.u));
	uv.u = (float)((phi + M_PI) / (2.0f * M_PI));
	uv.v = 0.5f - h / (hyperboloid->half_height * 2.0f);
	return (uv);
}
