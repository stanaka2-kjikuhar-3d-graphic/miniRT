/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paraboloid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:26:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"
#include "id.h"

#include "./loader_object_private.h"

bool	load_paraboloid(t_scene_input const *scene_input)
{
	t_object_id					id;
	t_paraboloid_input const	*input;
	t_material					material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->paraboloid);
	material = expand_to_material(&(input->material));
	if (!set_paraboloid_primitive(id, &(input->paraboloid)))
		return (false);
	set_material(id, &material);
	set_paraboloid_uv_layout(id, UV_DEFAULT, &(input->paraboloid));
	set_uv_checker(id, input->checker_count);
	set_paraboloid_aabb_info(id, get_primitive(id));
	return (true);
}
