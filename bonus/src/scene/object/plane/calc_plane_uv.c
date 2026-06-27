/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_uv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:24:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/27 18:11:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"

t_vec2	calc_plane_uv(t_plane const *plane, t_vec3 point)
{
	t_vec3	to_point;

	to_point = vec3_sub(point, plane->center);
	return ((t_vec2){\
		.u = vec3_dot(to_point, plane->onb.u), \
		.v = vec3_dot(to_point, plane->onb.v), \
	});
}
