/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 00:55:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circles(t_object const *object, t_vec3 dir);

bool	create_cylinder(t_input_cylinder const *input)
{
	t_object	object;
	float		cap_ratio;
	t_vec3		dir;

	object.type = OBJ_CYLINDER;
	object.material = input->material;
	object.uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
								/ (2.0f * (input->radius + input->half_height));
	object.uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->radius / (2.0f * (input->radius + input->half_height));
	object.uv.v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
	object.cylinder.center = input->center;
	dir = vec3_normalize(input->dir);
	object.cylinder.dir = dir;
	object.cylinder.radius = input->radius;
	object.cylinder.half_height = input->half_height;
	object.cylinder.onb.w = dir;
	compute_onb(object.cylinder.onb.w, \
		&(object.cylinder.onb.u), &(object.cylinder.onb.v));
	if (!create_object(&object))
		return (false);
	return (add_cap_circles(&object, dir));
}

static bool	add_cap_circles(t_object const *object, t_vec3 dir)
{
	t_input_circle	top;
	t_input_circle	bottom;

	top.material = object->material;
	top.uv,type = UV_UPPER_CAP;
	top.center = vec3_add(object->cylinder.center, \
					vec3_scale(object->cylinder.half_height, dir));
	top.normal = dir;
	top.radius = object->cylinder.radius;
	bottom.material = object->material;
	bottom.uv.type = UV_LOWER_CAP;
	bottom.center = vec3_add(object->cylinder.center, \
						vec3_scale(-(object->cylinder.half_height), dir));
	bottom.normal = vec3_scale(-1, dir);
	bottom.radius = object->cylinder.radius;
	return (create_circle(&top) && create_circle(&bottom));
}
