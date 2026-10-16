/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_material_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:59:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 21:51:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../parser_private.h"

void	bind_material_input(\
	t_optional_field *fields, t_material_input *material)
{
	fields[OPTIONAL_TEXTURE].value = &(material->texture);
	fields[OPTIONAL_CHECKER_COLOR1].value = &(material->checker.color1);
	fields[OPTIONAL_CHECKER_COLOR2].value = &(material->checker.color2);
	fields[OPTIONAL_BUMP_MAP].value = &(material->bump_map);
	fields[OPTIONAL_NORMAL_MAP].value = &(material->normal_map);
	fields[OPTIONAL_DIRECTX_NORMAL_MAP].value = &(material->directx_normal_map);
	fields[OPTIONAL_BUMP_STRENGTH].value = &(material->bump_strength);
	fields[OPTIONAL_METALNESS].value = &(material->metalness);
	fields[OPTIONAL_SHININESS].value = &(material->shininess);
}
