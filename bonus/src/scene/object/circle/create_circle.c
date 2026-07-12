/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 00:56:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_circle(t_input_circle const *input)
{
	t_object	object;

	object.type = OBJ_CIRCLE;
	object.material = input->material;
	if (object.uv.type == UV_UPPER_CAP)
	{
		object.uv.v_range \
			= (t_range){.max = 1.0f, .min = input->uv.v_range.max};
	}
	else if (object.uv.uv_type == UV_LOWER_CAP)
	{
		object.uv.v_range \
			= (t_range){.max = input->uv.v_range.min, .min = 0.0f};
	}
	object.circle.center = input->center;
	object.circle.normal = vec3_normalize(input->normal);
	object.circle.radius = input->radius;
	object.circle.onb.w = object.circle.normal;
	compute_onb(object.circle.onb.w, \
		&(object.circle.onb.u), &(object.circle.onb.v));
	return (create_object(&object));
}
