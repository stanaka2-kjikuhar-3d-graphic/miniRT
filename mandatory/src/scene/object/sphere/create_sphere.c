/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:12:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "aabb.h"
#include "matrix.h"
#include "object.h"
#include "range.h"

#include "../object_private.h"

static bool		set_sphere_primitive(\
					t_object *object, t_input_sphere const *input);
static t_aabb	calc_sphere_aabb(t_input_sphere const *input);

bool	create_sphere(t_input_sphere const *input)
{
	t_object	object;

	object.albedo = input->albedo;
	if (!set_sphere_primitive(&object, input))
		return (false);
	object.aabb = calc_sphere_aabb(input);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	return (create_object(&object));
}

static bool	set_sphere_primitive(t_object *object, t_input_sphere const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_SPHERE;
	frame.basis = calc_onb(vec3(0.0f, 0.0f, 1.0f));
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->radius);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_sphere_aabb(t_input_sphere const *input)
{
	return (calc_aabb_from_extent(input->center, \
				vec3(input->radius, input->radius, input->radius)));
}
