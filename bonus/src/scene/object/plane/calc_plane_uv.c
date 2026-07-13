/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_uv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:24:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 19:57:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

t_vec2	calc_plane_uv(t_plane const *plane, t_vec3 point, float pattern_size)
{
	t_vec3	to_point;
	t_vec2	uv;

	to_point = vec3_sub(point, plane->center);
	uv.u = vec3_dot(to_point, plane->onb.u) / pattern_size - 0.5f;
	uv.v = vec3_dot(to_point, plane->onb.v) / pattern_size - 0.5f;
	uv.u -= floorf(uv.u);
	uv.v -= floorf(uv.v);
	return (uv);
}
