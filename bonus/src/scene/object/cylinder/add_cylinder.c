/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 04:17:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circles(t_input_cylinder const *input, t_vec3 dir);

bool	add_cylinder(t_input_cylinder const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	object.type = OBJ_CYLINDER;
	object.cylinder.material = input->material;
	object.cylinder.center = input->center;
	object.cylinder.dir = dir;
	object.cylinder.radius = input->radius;
	object.cylinder.half_height = input->half_height;
	object.cylinder.onb.w = dir;
	compute_onb(object.cylinder.onb.w, \
		&(object.cylinder.onb.u), &(object.cylinder.onb.v));
	if (!add_object(&object))
		return (false);
	return (add_cap_circles(input, dir));
}

static bool	add_cap_circles(t_input_cylinder const *input, t_vec3 dir)
{
	t_input_circle	top;
	t_input_circle	bottom;

	top.material = input->material;
	top.center = vec3_add(input->center, \
			vec3_scale(input->half_height, dir));
	top.normal = dir;
	top.radius = input->radius;
	bottom.material = input->material;
	bottom.center = vec3_add(input->center, \
			vec3_scale(-(input->half_height), dir));
	bottom.normal = vec3_scale(-1, dir);
	bottom.radius = input->radius;
	return (add_circle(&top) && add_circle(&bottom));
}
