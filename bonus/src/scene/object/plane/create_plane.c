/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/23 00:47:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_plane(t_input_plane const *input)
{
	t_object	object;

	object.type = OBJ_PLANE;
	object.plane.center = input->center;
	object.plane.normal = vec3_normalize(input->normal);
	object.material.albedo = input->albedo;
	object.material.pattern_type = input->option.pattern_type;
	object.material.texture = input->option.texture;
	object.material.checker.color1 = input->option.checker_color1;
	object.material.checker.color2 = input->option.checker_color2;
	object.material.bump_map = input->option.bump_map;
	object.material.bump_strength = 1.0f;
	object.material.normal_map = input->option.normal_map;
	object.material.metalness = input->option.metalness;
	object.material.shininess = input->option.shininess;
	object.uv.type = UV_DEFAULT;
	object.uv.pattern_size = input->option.pattern_size;
	object.uv.u_per_v = 1.0f;
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.plane.onb.w = object.plane.normal;
	calc_onb(object.plane.onb.w, \
		&(object.plane.onb.u), &(object.plane.onb.v));
	return (create_object(&object));
}
