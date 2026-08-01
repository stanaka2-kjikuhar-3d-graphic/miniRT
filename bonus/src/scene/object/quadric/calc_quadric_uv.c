/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadric_uv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:40:32 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 19:40:32 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_quadric_uv(t_quadric const *q, t_onb const *onb, t_vec3 point)
{
	t_vec2	uv;
	t_vec3	to_point;
	float	h;
	t_vec3	radial;
	float	phi;

	to_point = vec3_sub(point, q->center);
	h = vec3_dot(to_point, q->axis);
	radial = vec3_normalize(vec3_sub(to_point, vec3_scale(h, q->axis)));
	phi = atan2f(vec3_dot(radial, onb->v), vec3_dot(radial, onb->u));
	uv.u = (float)((phi + M_PI) / (2.0f * M_PI));
	uv.v = (h - q->h_min) / (q->h_max - q->h_min);
	return (uv);
}
