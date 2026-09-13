/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_material_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:59:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 15:00:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../parser_private.h"

void	bind_input_material_option(\
	t_optional_field *fields, t_input_material_option *option)
{
	fields[OPTIONAL_TEXTURE].value = &(option->texture);
	fields[OPTIONAL_CHECKER_COLOR1].value = &(option->checker_color1);
	fields[OPTIONAL_CHECKER_COLOR2].value = &(option->checker_color2);
	fields[OPTIONAL_BUMP_MAP].value = &(option->bump_map);
	fields[OPTIONAL_NORMAL_MAP].value = &(option->normal_map);
	fields[OPTIONAL_DIRECTX_NORMAL_MAP].value = &(option->directx_normal_map);
	fields[OPTIONAL_BUMP_STRENGTH].value = &(option->bump_strength);
	fields[OPTIONAL_METALNESS].value = &(option->metalness);
	fields[OPTIONAL_SHININESS].value = &(option->shininess);
}
