/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:07:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "aabb.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "loader.h"
#include "object_loader.h"

#include "./object_loader_private.h"

static void	set_sphere_uv(t_uv *uv, t_sphere_input const *input);
static bool	set_sphere_primitive(\
				t_object *object, t_sphere_input const *input);
static void	set_sphere_aabb_info(\
				t_aabb_info *aabb_info, t_sphere_input const *input);

bool	create_sphere(t_scene_input const *scene_input)
{
	t_sphere_input const	*input;
	t_object				object;

	input = &(scene_input->sphere);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_sphere_uv(&(object.uv), input);
	if (!set_sphere_primitive(&object, input))
		return (false);
	set_sphere_aabb_info(&(object.aabb_info), input);
	return (create_object(&object));
}

static void	set_sphere_uv(t_uv *uv, t_sphere_input const *input)
{
	uv->type = UV_DEFAULT;
	set_uv_checker(uv, input->option.checker_count);
	uv->u_per_v = 2.0f;
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	uv->v_range = (t_range){.min = 0.0f, .max = 1.0f};
}

static bool	set_sphere_primitive(t_object *object, t_sphere_input const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_SPHERE;
	frame.basis = calc_onb(vec3(0.0f, 0.0f, 1.0f));
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->radius);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_sphere_aabb_info(\
	t_aabb_info *aabb_info, t_sphere_input const *input)
{
	aabb_info->aabb = calc_aabb_from_extent(input->center, \
						vec3(input->radius, input->radius, input->radius));
	aabb_info->centroid = calc_aabb_centroid(&(aabb_info->aabb));
	aabb_info->has_bounded_aabb = has_bounded_aabb(&(aabb_info->aabb));
}
