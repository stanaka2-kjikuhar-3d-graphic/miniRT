/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_lower_cap_circle(t_object const *object);
static void	set_cone_uv(t_object *object, t_input_cone const *input);

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
	object->uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	cap_ratio = input->radius \
					/ (2.0f * (input->radius + object->cone.generatrix));
	object->uv.v_range = (t_range){.max = 1.0f - cap_ratio, .min = 0.0f};
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
	input.option.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	input.option.v_range = (t_range){\
		.max = 1.0f, .min = object->uv.v_range.max};
	return (create_circle(&input));
}
