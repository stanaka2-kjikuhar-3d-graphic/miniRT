/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/27 01:41:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

void	set_material_from_option(t_material *material, t_color albedo, \
			t_material_option const *option)
{
	material->albedo = albedo;
	material->pattern_type = option->pattern_type;
	material->texture = option->texture;
	material->checker.color1 = option->checker_color1;
	material->checker.color2 = option->checker_color2;
	material->bump_map = option->bump_map;
	material->normal_map = option->normal_map;
	material->bump_strength = option->bump_strength;
	material->metalness = option->metalness;
	material->shininess = option->shininess;
}

void	set_option_from_material(t_material_option *option, \
			t_material const *material)
{
	option->pattern_type = material->pattern_type;
	option->texture = material->texture;
	option->checker_color1 = material->checker.color1;
	option->checker_color2 = material->checker.color2;
	option->bump_map = material->bump_map;
	option->normal_map = material->normal_map;
	option->bump_strength = material->bump_strength;
	option->metalness = material->metalness;
	option->shininess = material->shininess;
}
