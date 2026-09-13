/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:52:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "aabb.h"
#include "loader.h"
#include "object_loader.h"

#include "./object_loader_private.h"
#include "../loader_private.h"

static bool	add_cap_disc(t_object const *object, \
				t_cylinder_input const *input, t_vec3 dir, enum e_uv_type type);
static void	set_cylinder_uv(t_uv *uv, t_cylinder_input const *input);
static bool	set_cylinder_primitive(t_object *object, \
				t_cylinder_input const *input, t_vec3 dir);
static void	set_cylinder_aabb_info(t_aabb_info *aabb_info, \
				t_cylinder_input const *input, t_vec3 dir);

bool	create_cylinder(t_scene_input const *scene_input)
{
	t_cylinder_input const	*input;
	t_object				object;
	t_vec3					dir;

	input = &(scene_input->cylinder);
	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cylinder_uv(&(object.uv), input);
	if (!set_cylinder_primitive(&object, input, dir))
		return (false);
	set_cylinder_aabb_info(&(object.aabb_info), input, dir);
	if (!create_object(&object))
		return (false);
	return (add_cap_disc(&object, input, dir, UV_UPPER_CAP) \
				&& add_cap_disc(&object, input, dir, UV_LOWER_CAP));
}

static bool	add_cap_disc(t_object const *object, \
	t_cylinder_input const *src, t_vec3 dir, enum e_uv_type uv_type)
{
	t_scene_input	input;

	input.disc.albedo = object->material.albedo;
	if (uv_type == UV_UPPER_CAP)
		input.disc.normal = dir;
	else
		input.disc.normal = vec3_scale(-1.0f, dir);
	input.disc.center = vec3_add(src->center, \
						vec3_scale(src->half_height, input.disc.normal));
	input.disc.radius = src->radius;
	set_option_from_material(\
		&(input.disc.option.material), &(object->material));
	input.disc.option.uv_type = uv_type;
	input.disc.option.pattern_size = input.disc.radius * 2.0f;
	input.disc.option.u_per_v = object->uv.u_per_v;
	input.disc.option.checker_count = object->uv.checker_count;
	input.disc.option.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (uv_type == UV_UPPER_CAP)
		input.disc.option.v_range = (t_range){\
			.min = 0.0f, .max = object->uv.v_range.min};
	else
		input.disc.option.v_range = (t_range){\
			.min = object->uv.v_range.max, .max = 1.0f};
	return (create_disc(&input));
}

static bool	set_cylinder_primitive(\
	t_object *object, t_cylinder_input const *input, t_vec3 dir)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CYLINDER;
	frame.basis = calc_onb(dir);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->half_height);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_cylinder_uv(t_uv *uv, t_cylinder_input const *input)
{
	float	cap_ratio;

	uv->type = UV_DEFAULT;
	set_uv_checker(uv, input->option.checker_count);
	uv->u_per_v = (float)(2.0f * M_PI * input->radius) \
					/ (2.0f * (input->radius + input->half_height));
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->radius / (2.0f * (input->radius + input->half_height));
	uv->v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
}

static void	set_cylinder_aabb_info(\
	t_aabb_info *aabb_info, t_cylinder_input const *input, t_vec3 dir)
{
	t_vec3	disc_extent;
	t_vec3	top;
	t_vec3	bottom;

	disc_extent = vec3(\
		input->radius * sqrtf(1.0f - dir.x * dir.x), \
		input->radius * sqrtf(1.0f - dir.y * dir.y), \
		input->radius * sqrtf(1.0f - dir.z * dir.z) \
	);
	top = vec3_add(input->center, \
			vec3_scale(input->half_height, dir));
	bottom = vec3_sub(input->center, \
			vec3_scale(input->half_height, dir));
	aabb_info->aabb = union_aabb(\
						calc_aabb_from_extent(top, disc_extent), \
						calc_aabb_from_extent(bottom, disc_extent) \
					);
	aabb_info->centroid = calc_aabb_centroid(&(aabb_info->aabb));
	aabb_info->has_bounded_aabb = has_bounded_aabb(&(aabb_info->aabb));
}
