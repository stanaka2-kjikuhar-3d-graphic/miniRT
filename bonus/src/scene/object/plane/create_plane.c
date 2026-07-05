/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 19:23:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_plane(t_input_plane const *input)
{
	t_object	object;

	object.type = OBJ_PLANE;
	object.material = input->material;
	object.plane.center = input->center;
	object.plane.normal = vec3_normalize(input->normal);
	object.plane.onb.w = object.plane.normal;
	compute_onb(object.plane.onb.w, \
		&(object.plane.onb.u), &(object.plane.onb.v));
	return (create_object(&object));
}
