/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 17:00:24 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"
#include "id.h"

#include "./loader_object_private.h"

bool	load_plane(t_scene_input const *scene_input)
{
	t_id				object_id;
	t_plane_input const	*input;
	t_material			material;

	if (!create_object(&object_id))
		return (false);
	input = &(scene_input->plane);
	material = expand_to_material(&(input->material));
	if (!set_plane_primitive(object_id, &(input->plane)))
		return (false);
	set_material(object_id, &material);
	set_plane_uv_layout(object_id, UV_DEFAULT);
	set_uv_checker(object_id, input->checker_count);
	set_plane_uv_pattern(\
		object_id, input->pattern_size, input->plane.half_size);
	set_plane_aabb_info(object_id, &(input->plane));
	return (true);
}
