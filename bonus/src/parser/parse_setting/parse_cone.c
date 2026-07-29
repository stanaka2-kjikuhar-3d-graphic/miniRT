/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 11:42:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_cone_required(\
				char const **elements, t_input_cone *input);
static bool	parse_cone_optional(\
				char const **optional_elements, t_input_cone *input);

bool	parse_cone(char const **elements)
{
	size_t			count;
	t_input_cone	input;

	count = count_split(elements);
	if (count < 6)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_CO);
		return (false);
	}
	if (!parse_cone_required(elements, &input) \
		|| !parse_cone_optional(elements + 6, &input))
	{
		return (false);
	}
	return (create_cone(&input));
}

static bool	parse_cone_required(\
	char const **elements, t_input_cone *input)
{
	t_required_field const	fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->dir), parse_dir}, \
		{elements[3], &(input->radius), parse_radius}, \
		{elements[4], &(input->height), parse_size}, \
		{elements[5], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(fields, count));
}

static bool	parse_cone_optional(\
	char const **optional_elements, t_input_cone *input)
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
