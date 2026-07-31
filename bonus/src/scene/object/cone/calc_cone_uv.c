/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:37:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 18:41:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_cone_uv(t_cone const *cone, t_vec3 point)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	h;
	t_vec3	radial;
	float	phi;

	to_point = vec3_sub(point, cone->center);
	h = vec3_dot(to_point, cone->dir);
	radial = vec3_normalize(vec3_sub(to_point, vec3_scale(h, cone->dir)));
	phi = atan2f(vec3_dot(radial, cone->onb.v), \
					vec3_dot(radial, cone->onb.u));
	uv.u = (float)((phi + M_PI) / (2.0f * M_PI));
	uv.v = h / cone->height;
	return (uv);
}
