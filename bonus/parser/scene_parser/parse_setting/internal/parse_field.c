/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 22:51:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:41:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../parse_setting_private.h"

bool	parse_field(enum e_field_type type, \
	union u_field_parser parser, char const *element, union u_field_value value)
{
	if (type == FIELD_VEC3)
		return (parser.vector(element, value.vector));
	else if (type == FIELD_COLOR)
		return (parser.color(element, value.color));
	else if (type == FIELD_FLOAT)
		return (parser.floating_point(element, value.floating_point));
	else if (type == FIELD_INT)
		return (parser.integer(element, value.integer));
	else if (type == FIELD_LONG)
		return (parser.long_integer(element, value.long_integer));
	else if (type == FIELD_BOOL)
		return (parser.boolean(element, value.boolean));
	else if (type == FIELD_TEXTURE_ID)
		return (parser.texture_id(element, value.texture_id));
	return (false);
}
