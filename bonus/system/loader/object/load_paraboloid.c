/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paraboloid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:22:18 by stanaka2         ###   ########.fr       */
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
	t_id						object_id;
	t_paraboloid_input const	*input;
	t_material					material;

	if (!create_object(&object_id))
		return (false);
	input = &(scene_input->paraboloid);
	material = expand_to_material(&(input->material));
	if (!set_paraboloid_primitive(object_id, &(input->paraboloid)))
		return (false);
	set_material(object_id, &material);
	set_paraboloid_uv_layout(object_id, UV_DEFAULT, &(input->paraboloid));
	set_uv_checker(object_id, input->checker_count);
	set_paraboloid_aabb_info(object_id, get_primitive(object_id));
	return (true);
}
