/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_field_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:06:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:43:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_setting_private.h"

void	set_default_field_value(enum e_field_type type, \
	union u_field_value *value, union u_default_field_value default_value)
{
	if (type == FIELD_VEC3)
		*(value->vector) = default_value.vector;
	else if (type == FIELD_COLOR)
		*(value->color) = default_value.color;
	else if (type == FIELD_FLOAT)
		*(value->floating_point) = default_value.floating_point;
	else if (type == FIELD_INT)
		*(value->integer) = default_value.integer;
	else if (type == FIELD_LONG)
		*(value->long_integer) = default_value.long_integer;
	else if (type == FIELD_BOOL)
		*(value->boolean) = default_value.boolean;
	else if (type == FIELD_TEXTURE_ID)
		*(value->texture_id) = default_value.texture_id;
}
