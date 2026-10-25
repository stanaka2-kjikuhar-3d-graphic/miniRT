/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bump_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 17:10:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "object.h"
#include "color.h"
#include "texture.h"
#include "vector.h"

t_vec3	calc_bump_mapping(\
	t_object const *object, t_vec2 uv, t_mat3 const *tbn)
{
	t_texture_id	id;
	t_vec2			pixel_size;
	t_vec2			height_diff;

	id = object->material.bump_map_id;
	pixel_size.u = 1.0f / (float)(get_texture_size(id).width);
	pixel_size.v = 1.0f / (float)(get_texture_size(id).height);
	height_diff.u \
		= average_rgb(get_texture_uv_pixel(id, \
				(t_vec2){.u = uv.u - pixel_size.u, .v = uv.v})) \
			- average_rgb(get_texture_uv_pixel(id, \
				(t_vec2){.u = uv.u + pixel_size.u, .v = uv.v}));
	height_diff.v \
		= average_rgb(get_texture_uv_pixel(id, \
				(t_vec2){.u = uv.u, .v = uv.v - pixel_size.v})) \
			- average_rgb(get_texture_uv_pixel(id, \
				(t_vec2){.u = uv.u, .v = uv.v + pixel_size.v}));
	return (vec3_normalize(mat3_mul_vec3(tbn, vec3(\
		object->material.bump_strength \
			* height_diff.u * 0.5f / object->uv_info.layout.aspect, \
		object->material.bump_strength * height_diff.v * 0.5f, \
		1.0f))));
}
