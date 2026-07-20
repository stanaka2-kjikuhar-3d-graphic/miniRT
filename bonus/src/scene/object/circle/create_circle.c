/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/20 19:00:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_circle(t_input_circle const *input)
{
	t_object	object;

	object.type = OBJ_CIRCLE;
	object.circle.center = input->center;
	object.circle.normal = vec3_normalize(input->normal);
	object.circle.radius = input->radius;
	object.material.albedo = input->albedo;
	object.material.pattern_type = input->option.pattern_type;
	object.material.texture = input->option.texture;
	object.material.checker.color1 = input->option.checker_color1;
	object.material.checker.color2 = input->option.checker_color2;
	object.material.bump_map = input->option.bump_map;
	object.material.normal_map = input->option.normal_map;
	object.material.metalness = input->option.metalness;
	object.material.shininess = input->option.shininess;
	object.uv.type = input->option.uv_type;
	object.uv.pattern_size = input->option.pattern_size;
	object.uv.u_per_v = input->option.u_per_v;
	object.uv.u_range = input->option.u_range;
	object.uv.v_range = input->option.v_range;
	object.circle.onb.w = object.circle.normal;
	calc_onb(object.circle.onb.w, \
		&(object.circle.onb.u), &(object.circle.onb.v));
	return (create_object(&object));
}
