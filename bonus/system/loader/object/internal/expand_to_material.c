/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_to_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 07:13:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"
#include "../loader_object_private.h"

t_material	expand_to_material(\
	t_color albedo, t_material_input const *input)
{
	return ((t_material){\
		.albedo = albedo, \
		.pattern_type = input->pattern_type, \
		.texture = input->texture, \
		.checker = input->checker, \
		.normal_type = input->normal_type, \
		.bump_map = input->bump_map, \
		.normal_map = input->normal_map, \
		.directx_normal_map = input->directx_normal_map, \
		.bump_strength = input->bump_strength, \
		.metalness = input->metalness, \
		.shininess = input->shininess \
	});
}
