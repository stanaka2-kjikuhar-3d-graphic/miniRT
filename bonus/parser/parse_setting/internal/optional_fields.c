/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_fields.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 07:18:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:42:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include <stdbool.h>

#include "config.h"

#include "../parse_setting_private.h"
#include "../../parser_private.h"

static const t_optional_field	g_optional_fields[OPTIONAL_FIELD_COUNT] = {\
	[OPTIONAL_TEXTURE] = {\
		.key = "texture", \
		.format_msg = "texture=file.xpm", \
		.field_type = FIELD_TEXTURE_ID, \
		.parser = {.texture_id = parse_texture}, \
		.value = {.texture_id = NULL}, \
		.default_value = {.texture_id = {.is_valid = false}}, \
	}, \
	[OPTIONAL_CHECKER_COLOR1] = {\
		.key = "checker_color1", \
		.format_msg = "checker_color1=R,G,B [0 <= R,G,B <= 255]", \
		.field_type = FIELD_COLOR, \
		.parser = {.color = parse_color}, \
		.value = {.color = NULL}, \
		.default_value = {.color = {.r = 0.0f, .g = 0.0f, .b = 0.0f}}, \
	}, \
	[OPTIONAL_CHECKER_COLOR2] = {\
		.key = "checker_color2", \
		.format_msg = "checker_color2=R,G,B [0 <= R,G,B <= 255]", \
		.field_type = FIELD_COLOR, \
		.parser = {.color = parse_color}, \
		.value = {.color = NULL}, \
		.default_value = {.color = {.r = 1.0f, .g = 1.0f, .b = 1.0f}}, \
	}, \
	[OPTIONAL_BUMP_MAP] = {\
		.key = "bump_map", \
		.format_msg = "bump_map=file.xpm", \
		.field_type = FIELD_TEXTURE_ID, \
		.parser = {.texture_id = parse_texture}, \
		.value = {.texture_id = NULL}, \
		.default_value = {.texture_id = {.is_valid = false}}, \
	}, \
	[OPTIONAL_NORMAL_MAP] = {\
		.key = "normal_map", \
		.format_msg = "normal_map=file.xpm", \
		.field_type = FIELD_TEXTURE_ID, \
		.parser = {.texture_id = parse_texture}, \
		.value = {.texture_id = NULL}, \
		.default_value = {.texture_id = {.is_valid = false}}, \
	}, \
	[OPTIONAL_DIRECTX_NORMAL_MAP] = {\
		.key = "directx_normal_map", \
		.format_msg = "directx_normal_map=true/false", \
		.field_type = FIELD_BOOL, \
		.parser = {.boolean = parse_bool}, \
		.value = {.boolean = NULL}, \
		.default_value = {.boolean = false}, \
	}, \
	[OPTIONAL_BUMP_STRENGTH] = {\
		.key = "bump_strength", \
		.format_msg = "bump_strength=x [0.0 < x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_size}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = DEFAULT_BUMP_STRENGTH}, \
	}, \
	[OPTIONAL_METALNESS] = {\
		.key = "metalness", \
		.format_msg = "metalness=true/false", \
		.field_type = FIELD_BOOL, \
		.parser = {.boolean = parse_bool}, \
		.value = {.boolean = NULL}, \
		.default_value = {.boolean = false}, \
	}, \
	[OPTIONAL_SHININESS] = {\
		.key = "shininess", \
		.format_msg = "shininess=x [0.0 <= x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_shininess}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = DEFAULT_SHININESS}, \
	}, \
	[OPTIONAL_REFLECTIVITY] = {\
		.key = "reflectivity", \
		.format_msg = "reflectivity=x [0.0 <= x <= 1.0]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_reflectivity}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = DEFAULT_REFLECTIVITY}, \
	}, \
	[OPTIONAL_IOR] = {\
		.key = "ior", \
		.format_msg = "ior=x [0.0 <= x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_ior}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = DEFAULT_IOR}, \
	}, \
	[OPTIONAL_PATTERN_SIZE] = {\
		.key = "pattern_size", \
		.format_msg = "pattern_size=x [0.0 < x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_size}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = DEFAULT_PATTERN_SIZE}, \
	}, \
	[OPTIONAL_U_SIZE] = {\
		.key = "u_size", \
		.format_msg = "u_size=x [0.0 < x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = INFINITY}, \
	}, \
	[OPTIONAL_V_SIZE] = {\
		.key = "v_size", \
		.format_msg = "v_size=x [0.0 < x]", \
		.field_type = FIELD_FLOAT, \
		.parser = {.floating_point = parse_half_size}, \
		.value = {.floating_point = NULL}, \
		.default_value = {.floating_point = INFINITY}, \
	}, \
	[OPTIONAL_CHECKER_COUNT_U] = {\
		.key = "checker_count_u", \
		.format_msg = "checker_count_u=n [2 <= n <= 1024]", \
		.field_type = FIELD_INT, \
		.parser = {.integer = parse_checker_count}, \
		.value = {.integer = NULL}, \
		.default_value = {.integer = DEFAULT_CHECKER_COUNT}, \
	}, \
	[OPTIONAL_CHECKER_COUNT_V] = {\
		.key = "checker_count_v", \
		.format_msg = "checker_count_v=n [2 <= n <= 1024]", \
		.field_type = FIELD_INT, \
		.parser = {.integer = parse_checker_count}, \
		.value = {.integer = NULL}, \
		.default_value = {.integer = DEFAULT_CHECKER_COUNT}, \
	}, \
	[OPTIONAL_CHECKER_COUNT_U_EVEN] = {\
		.key = "checker_count_u", \
		.format_msg = "checker_count_u=n [2 <= n <= 1024, even number]", \
		.field_type = FIELD_INT, \
		.parser = {.integer = parse_checker_count_even}, \
		.value = {.integer = NULL}, \
		.default_value = {.integer = DEFAULT_CHECKER_COUNT}, \
	}, \
	[OPTIONAL_CHECKER_COUNT_V_EVEN] = {\
		.key = "checker_count_v", \
		.format_msg = "checker_count_v=n [2 <= n <= 1024, even number]", \
		.field_type = FIELD_INT, \
		.parser = {.integer = parse_checker_count_even}, \
		.value = {.integer = NULL}, \
		.default_value = {.integer = DEFAULT_CHECKER_COUNT}, \
	}
};

void	init_optional_fields(t_optional_field *fields)
{
	size_t	i;

	i = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		fields[i] = g_optional_fields[i];
		++i;
	}
}

void	bind_optional_field(t_optional_field *fields, \
	enum e_optional_field optional_type, void *value)
{
	bind_field_value(fields[optional_type].field_type, \
		&(fields[optional_type].is_set), &(fields[optional_type].value), value);
}

void	set_default_values(t_optional_field *fields)
{
	enum e_optional_field	i;

	i = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		if (fields[i].is_set)
		{
			set_default_field_value(fields[i].field_type, \
					&(fields[i].value), fields[i].default_value);
		}
		++i;
	}
}
