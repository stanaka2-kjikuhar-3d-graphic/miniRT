/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cap_disc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:31:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:25:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "vector.h"
#include "loader.h"
#include "loader_object.h"

t_material_input	calc_cap_disc_material(t_material const *material)
{
	return ((t_material_input){\
		.albedo = material->albedo, \
		.pattern_type = material->pattern_type, \
		.texture_id = material->texture_id, \
		.checker = material->checker, \
		.normal_type = material->normal_type, \
		.bump_map_id = material->bump_map_id, \
		.normal_map_id = material->normal_map_id, \
		.directx_normal_map = material->directx_normal_map, \
		.bump_strength = material->bump_strength, \
		.metalness = material->metalness, \
		.shininess = material->shininess \
	});
}

t_vec3	calc_cap_disc_normal(enum e_uv_type type, t_vec3 dir)
{
	if (type == UV_UPPER_CAP)
		return (dir);
	else
		return (vec3_scale(-1.0f, dir));
}

t_uv_layout	calc_cap_disc_uv_layout(\
	enum e_uv_type type, float aspect, t_range v_range)
{
	t_uv_layout	uv_layout;

	uv_layout.type = type;
	uv_layout.aspect = aspect;
	uv_layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (type == UV_UPPER_CAP)
	{
		uv_layout.v_range \
			= (t_range){.min = 0.0f, .max = v_range.min};
	}
	else if (type == UV_LOWER_CAP)
	{
		uv_layout.v_range \
			= (t_range){.min = v_range.max, .max = 1.0f};
	}
	return (uv_layout);
}

float	calc_cap_disc_pattern_size(float radius)
{
	return (radius * 2.0f);
}
