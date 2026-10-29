/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:44:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "loader.h"
#include "loader_object.h"
#include "logger.h"

#include "./parse_setting_private.h"

#define REQUIRED_COUNT 3

static bool	parse_plane_required(\
				char const **elements, t_plane_input *input);
static bool	parse_plane_optional(\
				char const **optional_elements, t_plane_input *input);

bool	parse_plane(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count < REQUIRED_COUNT)
	{
		print_log_line(LOG_ERROR, ERROR_FIELDS_COUNT);
		print_log_hint(LOG_ERROR, HINT_PL);
		return (false);
	}
	input->type = PLANE_INPUT;
	if (!parse_plane_required(elements, &(input->plane)) \
		|| !parse_plane_optional(elements + REQUIRED_COUNT, &(input->plane)))
	{
		return (false);
	}
	return (true);
}

static bool	parse_plane_required(\
	char const **elements, t_plane_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] \
		= bind_required_field(REQUIRED_COORDINATE, &(input->plane.center));
	fields[1] = bind_required_field(REQUIRED_NORMAL, &(input->plane.normal));
	fields[2] = bind_required_field(REQUIRED_COLOR, &(input->material.albedo));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}

static bool	parse_plane_optional(\
	char const **optional_elements, t_plane_input *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_fields(fields, &(input->material));
	bind_optional_field(fields, OPTIONAL_PATTERN_SIZE, &(input->pattern_size));
	bind_optional_field(fields, OPTIONAL_U_SIZE, &(input->plane.half_size.u));
	bind_optional_field(fields, OPTIONAL_V_SIZE, &(input->plane.half_size.v));
	bind_optional_field(fields, OPTIONAL_CHECKER_COUNT_U_EVEN, \
							&(input->checker_count.u));
	bind_optional_field(fields, OPTIONAL_CHECKER_COUNT_V_EVEN, \
							&(input->checker_count.v));
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->material.pattern_type = get_pattern_type(optional_elements);
	input->material.normal_type = get_normal_type(optional_elements);
	return (true);
}
