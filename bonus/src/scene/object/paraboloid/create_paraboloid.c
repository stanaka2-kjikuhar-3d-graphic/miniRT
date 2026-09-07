/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:21:47 by stanaka2         ###   ########.fr       */
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

static void	set_paraboloid_uv(t_uv *uv, t_input_paraboloid const *input);
static bool	set_paraboloid_primitive(t_object *object, \
				t_input_paraboloid const *input, t_vec3 dir);
static void	set_paraboloid_aabb_info(\
				t_aabb_info *aabb_info, t_primitive const *primitive);

bool	create_paraboloid(t_input_paraboloid const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_paraboloid_uv(&(object.uv), input);
	if (!set_paraboloid_primitive(&object, input, dir))
		return (false);
	set_paraboloid_aabb_info(&(object.aabb_info), &(object.primitive));
	return (create_object(&object));
}

static void	set_paraboloid_uv(t_uv *uv, t_input_paraboloid const *input)
{
	float	top_radius;

	top_radius = sqrtf(input->quadratic_coefficient * input->height);
	uv->type = UV_DEFAULT;
	set_uv_checker(uv, input->option.checker_count);
	uv->u_per_v = (float)(2.0f * M_PI * top_radius) / input->height;
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	uv->v_range = (t_range){.min = 0.0f, .max = 1.0f};
}

/*
  x^2 + y^2 = a * z  ->  X^2 + Y^2 = Z  needs s^2 = a * sz.
  taking sz = height gives s = sqrt(a * height) and Z in [0, 1].
*/
static bool	set_paraboloid_primitive(t_object *object, \
	t_input_paraboloid const *input, t_vec3 dir)
{
	t_primitive_frame	frame;
	float				radius;

	radius = sqrtf(input->quadratic_coefficient * input->height);
	frame.type = UNIT_PARABOLOID;
	frame.basis = calc_onb(dir);
	frame.origin = input->center;
	frame.scale = vec3(radius, radius, input->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_paraboloid_aabb_info(\
	t_aabb_info *aabb_info, t_primitive const *primitive)
{
	aabb_info->aabb = transform_aabb(&(primitive->to_world), \
						vec3(0.0f, 0.0f, 0.5f), vec3(1.0f, 1.0f, 0.5f));
	aabb_info->centroid = calc_aabb_centroid(&(aabb_info->aabb));
	aabb_info->has_bounded_aabb = has_bounded_aabb(&(aabb_info->aabb));
}
