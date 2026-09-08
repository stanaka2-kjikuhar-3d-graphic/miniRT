/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/30 19:27:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "aabb.h"

#include "../object_private.h"

static bool		add_lower_cap_circle(t_object const *object, \
					t_input_cone const *input, t_vec3 dir);
static bool		set_cone_primitive(\
					t_object *object, t_input_cone const *input, t_vec3 dir);
static void		set_cone_uv(t_uv *uv, t_input_cone const *input);
static t_aabb	calc_cone_aabb(t_input_cone const *input, t_vec3 dir);

bool	create_cone(t_input_cone const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cone_uv(&(object.uv), input);
	if (!set_cone_primitive(&object, input, dir))
		return (false);
	object.aabb = calc_cone_aabb(input, dir);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	if (!create_object(&object))
		return (false);
	return (add_lower_cap_circle(&object, input, dir));
}

static void	set_cone_uv(t_uv *uv, t_input_cone const *input)
{
	float	cap_ratio;
	float	generatrix;

	generatrix \
		= sqrtf(input->radius * input->radius + input->height * input->height);
	uv->type = UV_DEFAULT;
	set_uv_checker(uv, input->option.checker_count);
	uv->u_per_v = (float)(2.0f * M_PI * input->radius) \
					/ (input->radius + generatrix);
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->radius \
				/ (2.0f * (input->radius + generatrix));
	uv->v_range = (t_range){.min = 0.0f, .max = 1.0f - cap_ratio};
}

static bool	add_lower_cap_circle(t_object const *object, \
	t_input_cone const *src, t_vec3 dir)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	input.normal = vec3_scale(-1.0f, dir);
	input.center = src->center;
	input.radius = src->radius;
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
  so the frame sits at the apex and its w axis looks back along -dir.
*/
static bool	set_cone_primitive(\
	t_object *object, t_input_cone const *input, t_vec3 dir)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CONE;
	frame.basis = calc_onb(dir);
	frame.basis.row[X_AXIS].w *= -1;
	frame.basis.row[Y_AXIS].w *= -1;
	frame.basis.row[Z_AXIS].w *= -1;
	frame.origin = vec3_add(input->center, \
			vec3_scale(input->height, dir));
	frame.scale = vec3(input->radius, input->radius, input->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_cone_aabb(t_input_cone const *input, t_vec3 dir)
{
	t_vec3	circle_extent;
	t_aabb	circle_aabb;
	t_vec3	vertex;
	t_aabb	vertex_aabb;

	circle_extent = vec3(\
		input->radius * sqrtf(1.0f - dir.x * dir.x), \
		input->radius * sqrtf(1.0f - dir.y * dir.y), \
		input->radius * sqrtf(1.0f - dir.z * dir.z) \
	);
	circle_aabb = calc_aabb_from_extent(input->center, circle_extent);
	vertex = vec3_add(input->center, vec3_scale(input->height, dir));
	vertex_aabb = calc_aabb_from_extent(vertex, vec3(0.0f, 0.0f, 0.0f));
	return (union_aabb(circle_aabb, vertex_aabb));
}
