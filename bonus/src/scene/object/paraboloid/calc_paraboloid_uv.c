/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_uv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 00:55:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 21:01:49 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_paraboloid_uv(t_paraboloid const *paraboloid, t_vec3 point)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	h;
	t_vec3	radial;
	float	phi;

	to_point = vec3_sub(point, paraboloid->center);
	h = vec3_dot(to_point, paraboloid->dir);
	radial = vec3_normalize(\
			vec3_sub(to_point, vec3_scale(h, paraboloid->dir)));
	phi = atan2f(vec3_dot(radial, paraboloid->onb.v), \
					vec3_dot(radial, paraboloid->onb.u));
	uv.u = (float)((phi + M_PI) / (2.0f * M_PI));
	uv.v = h / paraboloid->height;
	return (uv);
}
