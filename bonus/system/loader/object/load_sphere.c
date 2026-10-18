/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:26:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"
#include "id.h"

#include "./loader_object_private.h"

bool	load_sphere(t_scene_input const *scene_input)
{
	t_object_id				id;
	t_sphere_input const	*input;
	t_material				material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->sphere);
	material = expand_to_material(&(input->material));
	if (!set_sphere_primitive(id, &(input->sphere)))
		return (false);
	set_material(id, &material);
	set_sphere_uv_layout(id, UV_DEFAULT);
	set_uv_checker(id, input->checker_count);
	set_sphere_aabb_info(id, &(input->sphere));
	return (true);
}
