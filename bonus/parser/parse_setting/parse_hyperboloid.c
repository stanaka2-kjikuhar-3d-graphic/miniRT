/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:43:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "loader.h"
#include "loader_object.h"
#include "logger.h"

#include "./parse_setting_private.h"

#define REQUIRED_COUNT 6

static bool	parse_hyperboloid_required(\
				char const **elements, t_hyperboloid_input *input);
static bool	parse_hyperboloid_optional(\
				char const **optional_elements, t_hyperboloid_input *input);

bool	parse_hyperboloid(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count < REQUIRED_COUNT)
	{
		print_log_line(LOG_ERROR, ERROR_FIELDS_COUNT);
		print_log_hint(LOG_ERROR, HINT_HB);
		return (false);
	}
	input->type = HYPERBOLOID_INPUT;
	if (!parse_hyperboloid_required(elements, &(input->hyperboloid)) \
		|| !parse_hyperboloid_optional(\
				elements + REQUIRED_COUNT, &(input->hyperboloid)))
	{
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_required(\
	char const **elements, t_hyperboloid_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = bind_required_field(REQUIRED_COORDINATE, \
					&(input->hyperboloid.center));
	fields[1] = bind_required_field(REQUIRED_DIR, &(input->hyperboloid.dir));
	fields[2] = bind_required_field(REQUIRED_CENTER_DIAMETER, \
					&(input->hyperboloid.center_radius));
	fields[3] = bind_required_field(REQUIRED_CAP_DIAMETER, \
					&(input->hyperboloid.cap_radius));
	fields[4] = bind_required_field(REQUIRED_HALF_HEIGHT, \
					&(input->hyperboloid.half_height));
	fields[5] = bind_required_field(REQUIRED_COLOR, &(input->material.albedo));
	if (!parse_required_fields(elements, fields, REQUIRED_COUNT))
		return (false);
	set_log_field("cap_diameter", elements[3]);
	if (input->hyperboloid.center_radius >= input->hyperboloid.cap_radius)
	{
		print_log_field(LOG_ERROR, ERROR_HB_RADIUS);
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_optional(\
	char const **optional_elements, t_hyperboloid_input *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_fields(fields, &(input->material));
	bind_optional_field(fields, OPTIONAL_CHECKER_COUNT_U_EVEN, \
							&(input->checker_count.u));
	bind_optional_field(fields, OPTIONAL_CHECKER_COUNT_V, \
							&(input->checker_count.v));
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->material.pattern_type = get_pattern_type(optional_elements);
	input->material.normal_type = get_normal_type(optional_elements);
	return (true);
}
