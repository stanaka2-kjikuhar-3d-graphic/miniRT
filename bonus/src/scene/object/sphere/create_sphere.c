/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 00:26:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool		set_primitive(t_object *object, t_input_sphere const *input);
static t_aabb	calc_sphere_aabb(t_sphere const *sphere);

bool	create_sphere(t_input_sphere const *input)
{
	t_object	object;

	object.type = OBJ_SPHERE;
	object.sphere.center = input->center;
	object.sphere.radius = input->radius;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = 2.0f;
	object.uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.uv.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.sphere.onb = (t_onb){\
		.u = vec3(1.0f, 0.0f, 0.0f), \
		.v = vec3(0.0f, 1.0f, 0.0f), \
		.w = vec3(0.0f, 0.0f, 1.0f)};
	if (!set_primitive(&object, input))
		return (false);
	object.aabb = calc_sphere_aabb(&(object.sphere));
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	return (create_object(&object));
}

static bool	set_primitive(t_object *object, t_input_sphere const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_SPHERE;
	frame.basis = basis_from_dir(vec3(0.0f, 0.0f, 1.0f));
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->radius);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_sphere_aabb(t_sphere const *sphere)
{
	return (calc_aabb_from_extent(sphere->center, \
				vec3(sphere->radius, sphere->radius, sphere->radius)));
}
