/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:10:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "material.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"

bool	load_plane(t_scene_input const *scene_input)
{
	t_object_id			id;
	t_plane_input const	*input;
	t_material			material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->plane);
	material = expand_to_material(&(input->material));
	if (!set_plane_primitive(id, &(input->plane)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_plane_uv_layout(id, UV_DEFAULT);
	set_uv_checker(id, input->checker_count);
	set_plane_uv_pattern(id, input->pattern_size, input->plane.half_size);
	set_plane_aabb_info(id, &(input->plane));
	return (true);
}
