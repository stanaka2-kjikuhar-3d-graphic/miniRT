/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal_mapping.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:44:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "color.h"
#include "ft_mlx.h"

t_vec3	calc_normal_mapping(t_object const *object, t_vec2 uv, t_onb const *tbn)
{
	t_color	color;
	t_vec3	normal;

	color = convert_uint_to_color(\
				*get_uv_pixel_addr(object->material.normal_map, uv));
	normal = (t_vec3){\
		.x = color.r * 2.0f - 1.0f, \
		.y = color.g * 2.0f - 1.0f, \
		.z = color.b * 2.0f - 1.0f
	};
	return (vec3_normalize(vec3_add(vec3_add(\
			vec3_scale(normal.x, tbn->u), \
			vec3_scale(normal.y, tbn->v)), \
			vec3_scale(normal.z, tbn->w)) \
	));
}
