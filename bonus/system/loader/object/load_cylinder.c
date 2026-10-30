/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:42:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "object.h"
#include "range.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"
#include "../loader_private.h"

static bool	add_cap_disc(enum e_uv_type uv_type, \
						t_object_id id, t_cylinder const *cylinder);

bool	load_cylinder(t_input const *input)
{
	t_object_id				id;
	t_cylinder_input const	*cylinder;
	t_material				material;

	if (!create_object(&id))
		return (false);
	cylinder = &(input->cylinder);
	material = expand_to_material(&(cylinder->material));
	if (!set_cylinder_primitive(id, &(cylinder->cylinder)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_cylinder_uv_layout(id, UV_DEFAULT, &(cylinder->cylinder));
	set_uv_checker(id, cylinder->checker_count);
	set_cylinder_aabb_info(id, &(cylinder->cylinder));
	return (add_cap_disc(UV_UPPER_CAP, id, &(cylinder->cylinder)) \
				&& add_cap_disc(UV_LOWER_CAP, id, &(cylinder->cylinder)));
}

static bool	add_cap_disc(\
	enum e_uv_type type, t_object_id id, t_cylinder const *cylinder)
{
	t_input			input;
	t_disc_input	disc;

	disc.disc.normal = calc_cap_disc_normal(type, cylinder->dir);
	disc.disc.center = vec3_add(cylinder->center, \
						vec3_scale(cylinder->half_height, disc.disc.normal));
	disc.disc.radius = cylinder->radius;
	disc.material = calc_cap_disc_material(get_object_material(id));
	disc.uv_layout = calc_cap_disc_uv_layout(type, \
		get_uv_layout(id)->aspect, get_uv_layout(id)->v_range);
	disc.pattern_size = calc_cap_disc_pattern_size(disc.disc.radius);
	disc.checker_count = get_uv_checker(id)->count;
	input.type = DISC_INPUT;
	input.disc = disc;
	return (load_disc(&input));
}
