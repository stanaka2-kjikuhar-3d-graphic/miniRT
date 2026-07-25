/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_circle_uv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:45:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:56:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_circle_uv(\
	t_circle const *circle, t_vec3 point, enum e_uv_type uv_type)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	phi;

	to_point = vec3_sub(point, circle->center);
	phi = atan2f(vec3_dot(to_point, circle->onb.v), \
					vec3_dot(to_point, circle->onb.u));
	uv = (t_vec2){\
			.u = (float)((phi + M_PI) / (2.0f * M_PI)), \
			.v = vec3_length(to_point) / circle->radius \
		};
	if (uv_type == UV_LOWER_CAP)
	{
		uv.u = 1.0f - uv.u;
		uv.v = 1.0f - uv.v;
	}
	return (uv);
}
