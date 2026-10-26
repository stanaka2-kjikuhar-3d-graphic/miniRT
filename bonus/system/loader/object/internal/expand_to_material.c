/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_to_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:09:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "loader_object.h"

#include "../loader_object_private.h"

t_material	expand_to_material(t_material_input const *input)
{
	return ((t_material){\
		.albedo = input->albedo, \
		.pattern_type = input->pattern_type, \
		.texture_id = input->texture_id, \
		.checker = input->checker, \
		.normal_type = input->normal_type, \
		.bump_map_id = input->bump_map_id, \
		.normal_map_id = input->normal_map_id, \
		.directx_normal_map = input->directx_normal_map, \
		.bump_strength = input->bump_strength, \
		.metalness = input->metalness, \
		.shininess = input->shininess, \
		.reflectivity = input->reflectivity, \
		.ior = input->ior \
	});
}
