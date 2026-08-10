/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 19:29:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool		add_lower_cap_circle(t_object const *object);
static bool		set_primitive(t_object *object, t_input_cone const *input);
static void		set_cone_uv(t_object *object, t_input_cone const *input);
static t_aabb	calc_cone_aabb(t_cone const *cone);

bool	create_cone(t_input_cone const *input)
{
	t_object	object;

	object.type = OBJ_CONE;
	object.cone.center = input->center;
	object.cone.dir = vec3_normalize(input->dir);
	object.cone.radius = input->radius;
	object.cone.height = input->height;
	object.cone.generatrix \
		= sqrtf(input->radius * input->radius + input->height * input->height);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cone_uv(&object, input);
	object.cone.onb.w = object.cone.dir;
	calc_onb(object.cone.onb.w, \
		&(object.cone.onb.u), &(object.cone.onb.v));
	cone_to_quadric(&(object.cone), &(object.cone.quadric));
	if (!set_primitive(&object, input))
		return (false);
	object.aabb = calc_cone_aabb(&(object.cone));
	if (!create_object(&object))
		return (false);
	return (add_lower_cap_circle(&object));
}

static void	set_cone_uv(t_object *object, t_input_cone const *input)
{
	float	cap_ratio;

	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
							/ (input->radius + object->cone.generatrix);
	object->uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->radius \
					/ (2.0f * (input->radius + object->cone.generatrix));
	object->uv.v_range = (t_range){.min = 0.0f, .max = 1.0f - cap_ratio};
}

static bool	add_lower_cap_circle(t_object const *object)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	input.normal = vec3_scale(-1.0f, object->cone.dir);
	input.center = object->cone.center;
	input.radius = object->cone.radius;
	set_option_from_material(&(input.option.material), &(object->material));
	input.option.uv_type = UV_LOWER_CAP;
	input.option.pattern_size = input.radius * 2.0f;
	input.option.u_per_v = object->uv.u_per_v;
	input.option.checker_count = object->uv.checker_count;
	input.option.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	input.option.v_range = (t_range){\
		.min = object->uv.v_range.max, .max = 1.0f};
	return (create_circle(&input));
}

/*
  the unit cone has its apex at z = 0 and opens toward +z,
  so the frame sits at the apex and looks back along -dir.
*/
static bool	set_primitive(t_object *object, t_input_cone const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CONE;
	frame.basis = basis_from_dir(vec3_scale(-1.0f, object->cone.dir));
	frame.origin = vec3_add(input->center, \
			vec3_scale(input->height, object->cone.dir));
	frame.scale = vec3(input->radius, input->radius, input->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_cone_aabb(t_cone const *cone)
{
	t_vec3	circle_extent;
	t_aabb	circle_aabb;
	t_vec3	vertex;
	t_aabb	vertex_aabb;

	circle_extent = vec3(\
		cone->radius * sqrtf(1.0f - cone->dir.x * cone->dir.x), \
		cone->radius * sqrtf(1.0f - cone->dir.y * cone->dir.y), \
		cone->radius * sqrtf(1.0f - cone->dir.z * cone->dir.z) \
	);
	circle_aabb = calc_aabb_from_extent(cone->center, circle_extent);
	vertex = vec3_add(cone->center, vec3_scale(cone->height, cone->dir));
	vertex_aabb = calc_aabb_from_extent(vertex, vec3(0.0f, 0.0f, 0.0f));
	return (union_aabb(circle_aabb, vertex_aabb));
}
