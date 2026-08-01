/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:16:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_sphere(t_input_sphere const *input)
{
	t_object	object;

	object.type = OBJ_SPHERE;
	object.sphere.center = input->center;
	object.sphere.radius = input->radius;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = 2.0f;
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.sphere.onb = (t_onb){\
		.u = vec3(1.0f, 0.0f, 0.0f), \
		.v = vec3(0.0f, 1.0f, 0.0f), \
		.w = vec3(0.0f, 0.0f, 1.0f)};
	return (create_object(&object));
}
