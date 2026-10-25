/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal_mapping.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 22:24:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "color.h"
#include "texture.h"
#include "material.h"

t_vec3	calc_normal_mapping(\
	t_material const *material, t_vec2 uv, t_mat3 const *tbn)
{
	t_texture_id	id;
	t_color			color;
	t_vec3			normal;

	id = material->normal_map_id;
	color = convert_uint_to_color(get_texture_uv_pixel(id, uv));
	normal = (t_vec3){\
		.x = color.r * 2.0f - 1.0f, \
		.y = 1.0f - color.g * 2.0f, \
		.z = color.b * 2.0f - 1.0f \
	};
	if (material->directx_normal_map)
		normal.y = -normal.y;
	return (vec3_normalize(mat3_mul_vec3(tbn, normal)));
}
