/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:43:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"

bool	load_sphere(t_input const *input)
{
	t_object_id				id;
	t_sphere_input const	*sphere;
	t_material				material;

	if (!create_object(&id))
		return (false);
	sphere = &(input->sphere);
	material = expand_to_material(&(sphere->material));
	if (!set_sphere_primitive(id, &(sphere->sphere)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_sphere_uv_layout(id, UV_DEFAULT);
	set_uv_checker(id, sphere->checker_count);
	set_sphere_aabb_info(id, &(sphere->sphere));
	return (true);
}
