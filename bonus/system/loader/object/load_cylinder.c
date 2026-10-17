/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 17:00:24 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "object.h"
#include "range.h"
#include "loader.h"
#include "loader_object.h"
#include "id.h"

#include "./loader_object_private.h"
#include "../loader_private.h"

static bool	add_cap_disc(enum e_uv_type uv_type, \
						t_id object_id, t_cylinder const *cylinder);

bool	load_cylinder(t_scene_input const *scene_input)
{
	t_id					object_id;
	t_cylinder_input const	*input;
	t_material				material;

	if (!create_object(&object_id))
		return (false);
	input = &(scene_input->cylinder);
	material = expand_to_material(&(input->material));
	if (!set_cylinder_primitive(object_id, &(input->cylinder)))
		return (false);
	set_material(object_id, &material);
	set_cylinder_uv_layout(object_id, UV_DEFAULT, &(input->cylinder));
	set_uv_checker(object_id, input->checker_count);
	set_cylinder_aabb_info(object_id, &(input->cylinder));
	return (add_cap_disc(UV_UPPER_CAP, object_id, &(input->cylinder)) \
				&& add_cap_disc(UV_LOWER_CAP, object_id, &(input->cylinder)));
}

static bool	add_cap_disc(\
	enum e_uv_type type, t_id object_id, t_cylinder const *cylinder)
{
	t_scene_input	scene_input;
	t_disc_input	input;

	input.disc.normal = calc_cap_disc_normal(type, cylinder->dir);
	input.disc.center = vec3_add(cylinder->center, \
						vec3_scale(cylinder->half_height, input.disc.normal));
	input.disc.radius = cylinder->radius;
	input.material = calc_cap_disc_material(get_material(object_id));
	input.uv_layout = calc_cap_disc_uv_layout(\
		type, get_uv_layout(object_id)->aspect, \
		get_uv_layout(object_id)->v_range);
	input.pattern_size = calc_cap_disc_pattern_size(input.disc.radius);
	input.checker_count = get_uv_checker(object_id)->count;
	scene_input.type = DISC_INPUT;
	scene_input.disc = input;
	return (load_disc(&scene_input));
}
