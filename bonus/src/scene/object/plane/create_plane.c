/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:32:02 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static bool	set_primitive(\
				t_object *object, t_input_plane const *input, t_vec3 normal);

bool	create_plane(t_input_plane const *input)
{
	t_object	object;
	t_vec3		normal;

	normal = vec3_normalize(input->normal);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	object.uv.pattern_size = input->option.pattern_size;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = 1.0f;
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f};
	if (!set_primitive(&object, input, normal))
		return (false);
	return (create_object(&object));
}

static bool	set_primitive(\
	t_object *object, t_input_plane const *input, t_vec3 normal)
{
	t_primitive_frame	frame;

	frame.type = UNIT_PLANE;
	frame.basis = calc_onb(normal);
	frame.origin = input->center;
	frame.scale = vec3(input->option.pattern_size, \
			input->option.pattern_size, 1.0f);
	frame.z_range = (t_range){.max = 0.0f, .min = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}
