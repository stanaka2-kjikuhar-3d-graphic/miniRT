/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_field_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 07:23:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:41:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../parse_setting_private.h"

void	bind_field_value(\
	enum e_field_type type, bool *is_set, union u_field_value *value, void *ptr)
{
	*is_set = true;
	if (type == FIELD_VEC3)
		value->vector = ptr;
	else if (type == FIELD_COLOR)
		value->color = ptr;
	else if (type == FIELD_FLOAT)
		value->floating_point = ptr;
	else if (type == FIELD_INT)
		value->integer = ptr;
	else if (type == FIELD_LONG)
		value->long_integer = ptr;
	else if (type == FIELD_BOOL)
		value->boolean = ptr;
	else if (type == FIELD_TEXTURE_ID)
		value->texture_id = ptr;
}
