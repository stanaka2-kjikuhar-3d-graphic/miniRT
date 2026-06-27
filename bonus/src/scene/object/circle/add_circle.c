/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/25 23:29:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	add_circle(t_input_circle const *input)
{
	t_object	object;

	object.type = OBJ_CIRCLE;
	object.circle.color = input->color;
	object.circle.center = input->center;
	object.circle.normal = vec3_normalize(input->normal);
	object.circle.radius = input->radius;
	object.circle.onb.w = object.circle.normal;
	compute_onb(object.circle.onb.w, \
		&(object.circle.onb.u), &(object.circle.onb.v));
	return (add_object(&object));
}
