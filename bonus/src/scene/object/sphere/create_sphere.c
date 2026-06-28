/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 05:59:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

#include "../object_private.h"

bool	create_sphere(t_input_sphere const *input)
{
	t_object	object;

	object.type = OBJ_SPHERE;
	object.sphere.material = input->material;
	object.sphere.center = input->center;
	object.sphere.radius = input->radius;
	object.sphere.onb = (t_onb){\
		.u = vec3(1.0f, 0.0f, 0.0f), \
		.v = vec3(0.0f, 1.0f, 0.0f), \
		.w = vec3(0.0f, 0.0f, 1.0f)};
	return (create_object(&object));
}
