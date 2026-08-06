/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:59:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_plane_required(\
				char const **elements, t_input_plane *input);
static bool	parse_plane_optional(\
				char const **optional_elements, t_input_plane *input);

bool	parse_plane(char const **elements)
{
	size_t			count;
	t_input_plane	input;

	count = count_split(elements);
	if (count < 4)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_PL);
		return (false);
	}
	if (!parse_plane_required(elements, &input) \
		|| !parse_plane_optional(elements + 4, &input))
	{
		return (false);
	}
	return (create_plane(&input));
}

static bool	parse_plane_required(\
	char const **elements, t_input_plane *input)
{
	t_required_field		fields[3];
	size_t const			count = sizeof(fields) / sizeof(t_required_field);

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_NORMAL, &(input->normal));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	return (parse_required_fields(elements, fields, count));
}

static bool	parse_plane_optional(\
	char const **optional_elements, t_input_plane *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
	fields[OPTIONAL_PATTERN_SIZE].value = &(input->option.pattern_size);
	fields[OPTIONAL_CHECKER_COUNT_U_EVEN].value \
		= &(input->option.checker_count.u);
	fields[OPTIONAL_CHECKER_COUNT_V_EVEN].value \
		= &(input->option.checker_count.v);
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	input->option.material.normal_type \
		= get_normal_type(optional_elements);
	return (true);
}
