/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bump_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/20 19:52:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "color.h"
#include "ft_mlx.h"

#include "./object_private.h"

t_vec3	calc_bump_mapping(t_object const *object, t_vec2 uv)
{
	t_vec2	pixel_size;
	float	h_u1;
	float	h_u2;
	float	h_v1;
	float	h_v2;

	pixel_size.u = 1.0 / object->material.bump_map->width;
	pixel_size.v = 1.0 / object->material.bump_map->height;
	h_u1 = average_rgb(get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u - pixel_size.u, .v = uv.v}));
	h_u2 = average_rgb(get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u + pixel_size.u, .v = uv.v}));
	h_v1 = average_rgb(get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u, .v = uv.v - pixel_size.v}));
	h_v2 = average_rgb(get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u, .v = uv.v + pixel_size.v}));
	return (vec3_normalize(vec3(\
				(h_u1 - h_u2) / (2 * pixel_size.u) * 10.0, \
				(h_v1 - h_v2) / (2 * pixel_size.v) * 10.0, \
				1.0f \
			)));
}
