/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bump_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:58:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "color.h"
#include "ft_mlx.h"

t_vec3	calc_bump_mapping(\
	t_object const *object, t_vec2 uv, t_mat3 const *tbn)
{
	t_vec2	pixel_size;
	float	h_u1;
	float	h_u2;
	float	h_v1;
	float	h_v2;

	pixel_size.u = 1.0f / (float)object->material.bump_map->width;
	pixel_size.v = 1.0f / (float)object->material.bump_map->height;
	h_u1 = average_rgb(*get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u - pixel_size.u, .v = uv.v}));
	h_u2 = average_rgb(*get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u + pixel_size.u, .v = uv.v}));
	h_v1 = average_rgb(*get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u, .v = uv.v - pixel_size.v}));
	h_v2 = average_rgb(*get_uv_pixel_addr(object->material.bump_map, \
				(t_vec2){.u = uv.u, .v = uv.v + pixel_size.v}));
	return (vec3_normalize(mat3_mul_vec3(tbn, vec3(\
		object->material.bump_strength \
			* (h_u1 - h_u2) * 0.5f / object->uv.u_per_v, \
		object->material.bump_strength * (h_v1 - h_v2) * 0.5f, \
		1.0f))));
}
