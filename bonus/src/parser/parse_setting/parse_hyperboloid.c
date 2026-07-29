/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 19:00:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_hyperboloid_required(\
				char const **elements, t_input_hyperboloid *input);
static bool	parse_hyperboloid_optional(\
				char const **optional_elements, t_input_hyperboloid *input);

bool	parse_hyperboloid(char const **elements)
{
	size_t				count;
	t_input_hyperboloid	input;

	count = count_split(elements);
	if (count < 7)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_HB);
		return (false);
	}
	if (!parse_hyperboloid_required(elements, &input) \
		|| !parse_hyperboloid_optional(elements + 7, &input))
	{
		return (false);
	}
	return (create_hyperboloid(&input));
}

static bool	parse_hyperboloid_required(\
	char const **elements, t_input_hyperboloid *input)
{
	t_required_field const	fields[] = {\
		{"coordinate", elements[1], &(input->center), parse_coordinate}, \
		{"dir", elements[2], &(input->dir), parse_dir}, \
		{"center_diameter", elements[3], \
			&(input->center_radius), parse_radius}, \
		{"cap_diameter", elements[4], &(input->cap_radius), parse_radius}, \
		{"height", elements[5], &(input->half_height), parse_half_height}, \
		{"color", elements[6], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(fields, count))
		return (false);
	set_error_strings((char const *[]){elements[3], elements[4], NULL});
	set_error_field("hb");
	if (input->center_radius >= input->cap_radius)
	{
		print_field_error(ERROR_HB_RADIUS, NULL);
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_optional(\
	char const **optional_elements, t_input_hyperboloid *input)
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
