/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hyperboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:47:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:42:26 by stanaka2         ###   ########.fr       */
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

bool	load_hyperboloid(t_input const *input)
{
	t_object_id					id;
	t_hyperboloid_input const	*hyperboloid;
	t_material					material;

	if (!create_object(&id))
		return (false);
	hyperboloid = &(input->hyperboloid);
	material = expand_to_material(&(hyperboloid->material));
	if (!set_hyperboloid_primitive(id, &(hyperboloid->hyperboloid)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_hyperboloid_uv_layout(id, UV_DEFAULT, &(hyperboloid->hyperboloid));
	set_uv_checker(id, hyperboloid->checker_count);
	set_hyperboloid_aabb_info(id, &(hyperboloid->hyperboloid));
	return (add_cap_disc(UV_UPPER_CAP, id, &(hyperboloid->hyperboloid)) \
			&& add_cap_disc(UV_LOWER_CAP, id, &(hyperboloid->hyperboloid)));
}

static bool	add_cap_disc(\
	enum e_uv_type type, t_object_id id, t_hyperboloid const *hyperboloid)
{
	t_input			input;
	t_disc_input	disc;

	disc.disc.normal = calc_cap_disc_normal(type, hyperboloid->dir);
	disc.disc.center = vec3_add(hyperboloid->center, \
					vec3_scale(hyperboloid->half_height, disc.disc.normal));
	disc.disc.radius = hyperboloid->cap_radius;
	disc.material = calc_cap_disc_material(get_object_material(id));
	disc.uv_layout = calc_cap_disc_uv_layout(type, \
		get_uv_layout(id)->aspect, get_uv_layout(id)->v_range);
	disc.pattern_size = calc_cap_disc_pattern_size(disc.disc.radius);
	disc.checker_count = get_uv_checker(id)->count;
	input.type = DISC_INPUT;
	input.disc = disc;
	return (load_disc(&input));
}
