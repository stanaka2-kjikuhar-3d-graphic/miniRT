/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_material_fields.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:59:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:41:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loader_object.h"

#include "../parse_setting_private.h"

void	bind_material_fields(\
	t_optional_field *fields, t_material_input *material)
{
	bind_optional_field(fields, OPTIONAL_TEXTURE, &(material->texture_id));
	bind_optional_field(fields, OPTIONAL_CHECKER_COLOR1, \
							&(material->checker.color1));
	bind_optional_field(fields, OPTIONAL_CHECKER_COLOR2, \
							&(material->checker.color2));
	bind_optional_field(fields, OPTIONAL_BUMP_MAP, &(material->bump_map_id));
	bind_optional_field(fields, OPTIONAL_NORMAL_MAP, \
							&(material->normal_map_id));
	bind_optional_field(fields, OPTIONAL_DIRECTX_NORMAL_MAP, \
							&(material->directx_normal_map));
	bind_optional_field(fields, OPTIONAL_BUMP_STRENGTH, \
							&(material->bump_strength));
	bind_optional_field(fields, OPTIONAL_METALNESS, &(material->metalness));
	bind_optional_field(fields, OPTIONAL_SHININESS, &(material->shininess));
	bind_optional_field(fields, OPTIONAL_REFLECTIVITY, \
							&(material->reflectivity));
	bind_optional_field(fields, OPTIONAL_IOR, &(material->ior));
}
