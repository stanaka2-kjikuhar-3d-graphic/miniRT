/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 23:38:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

bool	create_paraboloid(t_input_paraboloid const *input)
{
	t_object	object;

	object.type = OBJ_PARABOLOID;
	object.paraboloid.center = input->center;
	object.paraboloid.dir = vec3_normalize(input->dir);
	object.paraboloid.quadratic_coefficient = input->quadratic_coefficient;
	object.paraboloid.height = input->height;
	object.material.albedo = input->albedo;
	object.material.pattern_type = input->option.pattern_type;
	object.material.texture = input->option.texture;
	object.material.checker.color1 = input->option.checker_color1;
	object.material.checker.color2 = input->option.checker_color2;
	object.material.bump_map = input->option.bump_map;
	object.material.normal_map = input->option.normal_map;
	object.material.metalness = input->option.metalness;
	object.material.shininess = input->option.shininess;
	object.uv.type = UV_DEFAULT;
	object.uv.u_per_v = 1.0f; // TODO
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.paraboloid.onb.w = object.paraboloid.dir;
	calc_onb(object.paraboloid.onb.w, \
		&(object.paraboloid.onb.u), &(object.paraboloid.onb.v));
	return (create_object(&object));
}
