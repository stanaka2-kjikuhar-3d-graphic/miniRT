/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:35:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool	add_lower_cap_circle(t_object const *object, \
				t_input_cone const *input, t_vec3 dir);
static bool	set_primitive(\
				t_object *object, t_input_cone const *input, t_vec3 dir);
static void	set_cone_uv(t_object *object, t_input_cone const *input);

bool	create_cone(t_input_cone const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cone_uv(&object, input);
	if (!set_primitive(&object, input, dir))
		return (false);
	if (!create_object(&object))
		return (false);
	return (add_lower_cap_circle(&object, input, dir));
}

static void	set_cone_uv(t_object *object, t_input_cone const *input)
{
	float	cap_ratio;
	float	generatrix;

	generatrix \
		= sqrtf(input->radius * input->radius + input->height * input->height);
	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
							/ (input->radius + generatrix);
	object->uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	cap_ratio = input->radius \
					/ (2.0f * (input->radius + generatrix));
	object->uv.v_range = (t_range){.max = 1.0f - cap_ratio, .min = 0.0f};
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
	input.option.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	input.option.v_range = (t_range){\
		.max = 1.0f, .min = object->uv.v_range.max};
	return (create_circle(&input));
}

/*
  the unit cone has its apex at z = 0 and opens toward +z,
  so the frame sits at the apex and looks back along -dir.
*/
static bool	set_primitive(\
	t_object *object, t_input_cone const *input, t_vec3 dir)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CONE;
	frame.basis = calc_onb(vec3_scale(-1.0f, dir));
	frame.origin = vec3_add(input->center, \
			vec3_scale(input->height, dir));
	frame.scale = vec3(input->radius, input->radius, input->height);
	frame.z_range = (t_range){.max = 1.0f, .min = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}
