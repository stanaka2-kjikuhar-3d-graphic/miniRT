/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_required_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 18:01:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../parser_private.h"

static const t_required_field	g_required_fields[REQUIRED_FIELD_COUNT] = {\
	[REQUIRED_COORDINATE] = {NULL, "coordinate", parse_coordinate}, \
	[REQUIRED_DIR] = {NULL, "dir", parse_dir}, \
	[REQUIRED_NORMAL] = {NULL, "normal", parse_dir}, \
	[REQUIRED_COLOR] = {NULL, "color", parse_color}, \
	[REQUIRED_BRIGHTNESS] = {NULL, "brightness", parse_brightness}, \
	[REQUIRED_FOV] = {NULL, "fov", parse_fov}, \
	[REQUIRED_DIAMETER] = {NULL, "diameter", parse_half_size}, \
	[REQUIRED_CENTER_DIAMETER] = {NULL, "center_diameter", parse_half_size}, \
	[REQUIRED_CAP_DIAMETER] = {NULL, "cap_diameter", parse_half_size}, \
	[REQUIRED_HALF_HEIGHT] = {NULL, "height", parse_half_size}, \
	[REQUIRED_HEIGHT] = {NULL, "height", parse_size}, \
	[REQUIRED_COEFFICIENT] = {NULL, "coefficient", parse_size}, \
	[REQUIRED_ANGLE] = {NULL, "angle", parse_angle} \
};

t_required_field	build_required_field(\
	enum e_required_field field, void *value)
{
	t_required_field	required_field;

	required_field = g_required_fields[field];
	required_field.value = value;
	return (required_field);
}
