/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_disc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/10 16:15:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"

bool	load_disc(t_scene_input const *scene_input)
{
	size_t				id;
	t_disc_input const	*input;
	t_material			material;

	if (!create_object(&id))
		return (false);
	input = &(scene_input->disc);
	material = expand_to_material(input->material.albedo, &(input->material));
	if (!set_disc_primitive(id, &(input->disc)))
		return (false);
	set_material(id, &material);
	set_disc_uv_layout(id, &(input->uv_layout));
	set_uv_checker(id, input->checker_count);
	set_disc_uv_pattern(id, input->pattern_size);
	set_disc_aabb_info(id, &(input->disc));
	return (true);
}
