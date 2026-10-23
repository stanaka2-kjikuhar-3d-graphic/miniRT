/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_required_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/23 07:26:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../parse_setting_private.h"
#include "../../parser_private.h"

static const t_required_field	g_required_fields[REQUIRED_FIELD_COUNT] = {\
	[REQUIRED_COORDINATE] = {\
		.field = "coordinate", \
		.field_type = FIELD_VEC3, \
		.parser = {.vector = parse_coordinate}, \
		.value = {.vector = NULL} \
	}, \
	[REQUIRED_DIR] = {\
		.field = "dir", \
		.field_type = FIELD_VEC3, \
		.parser = {.vector = parse_dir}, \
		.value = {.vector = NULL} \
	}, \
	[REQUIRED_NORMAL] = {\
		.field = "normal", \
		.field_type = FIELD_VEC3, \
		.parser = {.vector = parse_dir}, \
		.value = {.vector = NULL} \
	}, \
	[REQUIRED_COLOR] = {\
		.field = "color", \
		.field_type = FIELD_COLOR, \
		.parser = {.color = parse_color}, \
		.value = {.color = NULL} \
	}, \
	[REQUIRED_BRIGHTNESS] = {\
		.field = "brightness", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_brightness}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_FOV] = {\
		.field = "fov", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_fov}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_DIAMETER] = {\
		.field = "diameter", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_CENTER_DIAMETER] = {\
		.field = "center_diameter", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_CAP_DIAMETER] = {\
		.field = "cap_diameter", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_HALF_HEIGHT] = {\
		.field = "height", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_HEIGHT] = {\
		.field = "height", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_COEFFICIENT] = {\
		.field = "coefficient", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_size}, \
		.value = {.floating_point = NULL} \
	}, \
	[REQUIRED_ANGLE] = {\
		.field = "angle", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_angle}, \
		.value = {.floating_point = NULL} \
	}, \
};

t_required_field	bind_required_field(\
	enum e_required_field field, void *value)
{
	t_required_field	required_field;

	required_field = g_required_fields[field];
	bind_field_value(required_field.field_type, \
		&(required_field.is_set), &(required_field.value), value);
	return (required_field);
}
