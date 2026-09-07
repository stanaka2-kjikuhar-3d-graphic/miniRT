/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:45:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "aabb.h"
#include "config.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "vector.h"

#include "../object_private.h"

static bool	set_circle_primitive(\
				t_object *object, t_input_circle const *input, t_vec3 normal);
static void	set_circle_aabb_info(t_aabb_info *aabb_info, \
				t_input_circle const *input, t_vec3 normal);

bool	create_circle(t_input_circle const *input)
{
	t_object	object;
	t_vec3		normal;

	object.albedo = input->albedo;
	normal = vec3_normalize(input->normal);
	if (!set_circle_primitive(&object, input, normal))
		return (false);
	set_circle_aabb_info(&(object.aabb_info), input, normal);
	return (create_object(&object));
}

static bool	set_circle_primitive(\
	t_object *object, t_input_circle const *input, t_vec3 normal)
{
	t_primitive_frame	frame;

	frame.type = UNIT_DISC;
	frame.basis = calc_onb(normal);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, 1.0f);
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_circle_aabb_info(\
	t_aabb_info *aabb_info, t_input_circle const *input, t_vec3 normal)
{
	t_vec3	extent;

	extent = vec3(\
		input->radius * sqrtf(1.0f - normal.x * normal.x), \
		input->radius * sqrtf(1.0f - normal.y * normal.y), \
		input->radius * sqrtf(1.0f - normal.z * normal.z) \
	);
	aabb_info->aabb = calc_aabb_from_extent(input->center, extent);
	aabb_info->centroid = calc_aabb_centroid(&(aabb_info->aabb));
	aabb_info->has_bounded_aabb = has_bounded_aabb(&(aabb_info->aabb));
}
