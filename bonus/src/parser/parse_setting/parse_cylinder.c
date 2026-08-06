/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:58:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_cylinder_required(\
				char const **elements, t_input_cylinder *input);
static bool	parse_cylinder_optional(\
				char const **optional_elements, t_input_cylinder *input);

bool	parse_cylinder(char const **elements)
{
	size_t				count;
	t_input_cylinder	input;

	count = count_split(elements);
	if (count < 6)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_CY);
		return (false);
	}
	if (!parse_cylinder_required(elements, &input) \
		|| !parse_cylinder_optional(elements + 6, &input))
	{
		return (false);
	}
	return (create_cylinder(&input));
}

static bool	parse_cylinder_required(\
	char const **elements, t_input_cylinder *input)
{
	t_required_field		fields[5];
	size_t const			count = sizeof(fields) / sizeof(t_required_field);

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_DIAMETER, &(input->radius));
	fields[3] = build_required_field(REQUIRED_HALF_HEIGHT, \
		&(input->half_height));
	fields[4] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	return (parse_required_fields(elements, fields, count));
}

static bool	parse_cylinder_optional(\
	char const **optional_elements, t_input_cylinder *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
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
