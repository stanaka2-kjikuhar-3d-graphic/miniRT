/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:42:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_paraboloid_required(\
				char const **elements, t_input_paraboloid *input);
static bool	parse_paraboloid_optional(\
				char const **optional_elements, t_input_paraboloid *input);

bool	parse_paraboloid(char const **elements)
{
	size_t				count;
	t_input_paraboloid	input;

	count = count_split(elements);
	if (count < 6)
	{
		print_line_error(ERROR_PB_COUNT, HINT_PB);
		return (false);
	}
	if (!parse_paraboloid_required(elements, &input) \
		|| !parse_paraboloid_optional(elements + 6, &input))
	{
		return (false);
	}
	return (create_paraboloid(&input));
}

static bool	parse_paraboloid_required(\
	char const **elements, t_input_paraboloid *input)
{
	t_required_field const	fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->dir), parse_dir}, \
		{elements[3], &(input->quadratic_coefficient), parse_size}, \
		{elements[4], &(input->height), parse_size}, \
		{elements[5], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(fields, count));
}

static bool	parse_paraboloid_optional(\
	char const **optional_elements, t_input_paraboloid *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
	if (!parse_optional_fields(optional_elements, fields))
	{
		return (false);
	}
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	return (true);
}
