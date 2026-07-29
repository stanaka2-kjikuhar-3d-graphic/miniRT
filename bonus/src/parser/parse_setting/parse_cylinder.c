/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:52:24 by stanaka2         ###   ########.fr       */
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
	t_required_field const	fields[] = {\
		{"coordinate", elements[1], &(input->center), parse_coordinate}, \
		{"dir", elements[2], &(input->dir), parse_dir}, \
		{"diameter", elements[3], &(input->radius), parse_radius}, \
		{"height", elements[4], &(input->half_height), parse_half_height}, \
		{"color", elements[5], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(fields, count));
}

static bool	parse_cylinder_optional(\
	char const **optional_elements, t_input_cylinder *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	input->option.material.normal_type \
		= get_normal_type(optional_elements);
	return (true);
}
