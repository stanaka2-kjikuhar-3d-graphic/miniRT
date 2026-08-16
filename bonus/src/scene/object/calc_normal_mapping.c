/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal_mapping.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:37:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:58:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "color.h"
#include "ft_mlx.h"

t_vec3	calc_normal_mapping(\
	t_object const *object, t_vec2 uv, t_mat3 const *tbn)
{
	t_color	color;
	t_vec3	normal;

	color = convert_uint_to_color(\
				*get_uv_pixel_addr(object->material.normal_map, uv));
	normal = (t_vec3){\
		.x = color.r * 2.0f - 1.0f, \
		.y = 1.0f - color.g * 2.0f, \
		.z = color.b * 2.0f - 1.0f \
	};
	if (object->material.directx_normal_map)
		normal.y = -normal.y;
	return (vec3_normalize(mat3_mul_vec3(tbn, normal)));
}
