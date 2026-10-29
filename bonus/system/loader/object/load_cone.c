/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:08:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "material.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"
#include "../loader_private.h"

static bool	add_lower_cap_disc(t_object_id id, t_cone const *cone);

bool	load_cone(t_scene_input const *scene_input)
{
	t_object_id			id;
	t_cone_input const	*input;
	t_material			material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->cone);
	material = expand_to_material(&(input->material));
	if (!set_cone_primitive(id, &(input->cone)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_cone_uv_layout(id, UV_DEFAULT, &(input->cone));
	set_uv_checker(id, input->checker_count);
	set_cone_aabb_info(id, &(input->cone));
	return (add_lower_cap_disc(id, &(input->cone)));
}

static bool	add_lower_cap_disc(t_object_id id, t_cone const *cone)
{
	t_scene_input	scene_input;
	t_disc_input	input;

	input.disc.normal = calc_cap_disc_normal(UV_LOWER_CAP, cone->dir);
	input.disc.center = cone->center;
	input.disc.radius = cone->radius;
	input.material = calc_cap_disc_material(get_object_material(id));
	input.uv_layout = calc_cap_disc_uv_layout(UV_LOWER_CAP, \
		get_uv_layout(id)->aspect, get_uv_layout(id)->v_range);
	input.pattern_size = calc_cap_disc_pattern_size(input.disc.radius);
	input.checker_count = get_uv_checker(id)->count;
	scene_input.type = DISC_INPUT;
	scene_input.disc = input;
	return (load_disc(&scene_input));
}
