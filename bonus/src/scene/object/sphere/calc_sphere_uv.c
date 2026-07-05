/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_uv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:55:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 13:13:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_sphere_uv(t_sphere const *sphere, t_vec3 point)
{
	t_vec3	normal;
	float	phi;
	float	theta;

	normal = vec3_normalize(vec3_sub(point, sphere->center));
	phi = atan2f(normal.y, normal.x);
	theta = asinf(fminf(1.0f, fmaxf(-1.0f, normal.z)));
	return ((t_vec2){\
		.u = (float)((phi + M_PI) / (2.0f * M_PI)), \
		.v = 1.0f - (float)((theta + M_PI_2) / M_PI), \
	});
}
