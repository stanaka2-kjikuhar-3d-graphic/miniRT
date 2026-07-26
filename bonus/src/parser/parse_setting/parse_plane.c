/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:58:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "config.h"
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
		print_line_error(ERROR_PL_COUNT, HINT_PL);
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
	t_required_field const	fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->normal), parse_dir}, \
		{elements[3], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(fields, count));
}

static bool	parse_plane_optional(\
	char const **optional_elements, t_input_plane *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
	fields[OPTIONAL_PATTERN_SIZE].value = &(input->option.pattern_size);
	if (!parse_optional_fields(optional_elements, fields))
	{
		return (false);
	}
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	return (true);
}
