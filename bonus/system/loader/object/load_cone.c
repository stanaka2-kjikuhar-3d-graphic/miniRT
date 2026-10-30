/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:39:30 by stanaka2         ###   ########.fr       */
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

static bool	add_lower_cap_disc(t_object_id id, t_cone const *cone);

bool	load_cone(t_input const *input)
{
	t_object_id			id;
	t_cone_input const	*cone;
	t_material			material;

	if (!create_object(&id))
		return (false);
	cone = &(input->cone);
	material = expand_to_material(&(cone->material));
	if (!set_cone_primitive(id, &(cone->cone)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_cone_uv_layout(id, UV_DEFAULT, &(cone->cone));
	set_uv_checker(id, cone->checker_count);
	set_cone_aabb_info(id, &(cone->cone));
	return (add_lower_cap_disc(id, &(cone->cone)));
}

static bool	add_lower_cap_disc(t_object_id id, t_cone const *cone)
{
	t_input			input;
	t_disc_input	disc;

	disc.disc.normal = calc_cap_disc_normal(UV_LOWER_CAP, cone->dir);
	disc.disc.center = cone->center;
	disc.disc.radius = cone->radius;
	disc.material = calc_cap_disc_material(get_object_material(id));
	disc.uv_layout = calc_cap_disc_uv_layout(UV_LOWER_CAP, \
		get_uv_layout(id)->aspect, get_uv_layout(id)->v_range);
	disc.pattern_size = calc_cap_disc_pattern_size(disc.disc.radius);
	disc.checker_count = get_uv_checker(id)->count;
	input.type = DISC_INPUT;
	input.disc = disc;
	return (load_disc(&input));
}
