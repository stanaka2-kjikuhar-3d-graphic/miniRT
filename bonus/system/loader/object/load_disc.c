/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_disc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:22:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"
#include "id.h"

#include "./loader_object_private.h"

bool	load_disc(t_scene_input const *scene_input)
{
	t_id				object_id;
	t_disc_input const	*input;
	t_material			material;

	if (!create_object(&object_id))
		return (false);
	input = &(scene_input->disc);
	material = expand_to_material(&(input->material));
	if (!set_disc_primitive(object_id, &(input->disc)))
		return (false);
	set_material(object_id, &material);
	set_disc_uv_layout(object_id, &(input->uv_layout));
	set_uv_checker(object_id, input->checker_count);
	set_disc_uv_pattern(object_id, input->pattern_size);
	set_disc_aabb_info(object_id, &(input->disc));
	return (true);
}
