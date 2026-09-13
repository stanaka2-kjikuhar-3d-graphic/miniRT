/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:51:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "loader.h"
#include "object_loader.h"
#include "ft_error.h"

#include "../parser_private.h"

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
		print_line_error(ERROR_FIELDS_COUNT, HINT_HB);
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

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_CENTER_DIAMETER, \
		&(input->center_radius));
	fields[3] = build_required_field(REQUIRED_CAP_DIAMETER, \
		&(input->cap_radius));
	fields[4] = build_required_field(REQUIRED_HALF_HEIGHT, \
		&(input->half_height));
	fields[5] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	if (!parse_required_fields(elements, fields, REQUIRED_COUNT))
		return (false);
	set_error_field("cap_diameter", elements[3]);
	if (input->center_radius >= input->cap_radius)
	{
		print_field_error(ERROR_HB_RADIUS, NULL);
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_optional(\
	char const **optional_elements, t_hyperboloid_input *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option_input(fields, &(input->option.material));
	fields[OPTIONAL_CHECKER_COUNT_U_EVEN].value \
		= &(input->option.checker_count.u);
	fields[OPTIONAL_CHECKER_COUNT_V].value = &(input->option.checker_count.v);
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	input->option.material.normal_type \
		= get_normal_type(optional_elements);
	return (true);
}
