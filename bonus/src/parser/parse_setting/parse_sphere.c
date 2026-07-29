/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 11:42:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_sphere_required(\
				char const **elements, t_input_sphere *input);
static bool	parse_sphere_optional(\
				char const **optional_elements, t_input_sphere *input);

bool	parse_sphere(char const **elements)
{
	size_t			count;
	t_input_sphere	input;

	count = count_split(elements);
	if (count < 4)
	{
		print_line_error(ERROR_SP_COUNT, HINT_SP);
		return (false);
	}
	if (!parse_sphere_required(elements, &input) \
		|| !parse_sphere_optional(elements + 4, &input))
	{
		return (false);
	}
	return (create_sphere(&input));
}

static bool	parse_sphere_required(\
	char const **elements, t_input_sphere *input)
{
	t_required_field const	fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->radius), parse_radius}, \
		{elements[3], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(fields, count));
}

static bool	parse_sphere_optional(\
	char const **optional_elements, t_input_sphere *input)
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
