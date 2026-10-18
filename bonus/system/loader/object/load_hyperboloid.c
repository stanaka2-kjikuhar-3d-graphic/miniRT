/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hyperboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:47:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:04:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "vector.h"
#include "range.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"
#include "../loader_private.h"

static bool	add_cap_disc(enum e_uv_type uv_type, \
							t_object_id id, t_hyperboloid const *hyperboloid);

bool	load_hyperboloid(t_scene_input const *scene_input)
{
	t_object_id					id;
	t_hyperboloid_input const	*input;
	t_material					material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->hyperboloid);
	material = expand_to_material(&(input->material));
	if (!set_hyperboloid_primitive(id, &(input->hyperboloid)))
		return (false);
	set_material(id, &material);
	set_hyperboloid_uv_layout(id, UV_DEFAULT, &(input->hyperboloid));
	set_uv_checker(id, input->checker_count);
	set_hyperboloid_aabb_info(id, &(input->hyperboloid));
	return (add_cap_disc(UV_UPPER_CAP, id, &(input->hyperboloid)) \
			&& add_cap_disc(UV_LOWER_CAP, id, &(input->hyperboloid)));
}

static bool	add_cap_disc(\
	enum e_uv_type type, t_object_id id, t_hyperboloid const *hyperboloid)
{
	t_scene_input	scene_input;
	t_disc_input	input;

	input.disc.normal = calc_cap_disc_normal(type, hyperboloid->dir);
	input.disc.center = vec3_add(hyperboloid->center, \
					vec3_scale(hyperboloid->half_height, input.disc.normal));
	input.disc.radius = hyperboloid->cap_radius;
	input.material = calc_cap_disc_material(get_material(id));
	input.uv_layout = calc_cap_disc_uv_layout(type, \
		get_uv_layout(id)->aspect, get_uv_layout(id)->v_range);
	input.pattern_size = calc_cap_disc_pattern_size(input.disc.radius);
	input.checker_count = get_uv_checker(id)->count;
	scene_input.type = DISC_INPUT;
	scene_input.disc = input;
	return (load_disc(&scene_input));
}
