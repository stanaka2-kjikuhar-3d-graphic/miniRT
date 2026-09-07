/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:56:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 5

static bool	parse_cylinder_required(\
				char const **elements, t_input_cylinder *input);

bool	parse_cylinder(char const **elements)
{
	size_t				count;
	t_input_cylinder	input;

	count = count_split(elements);
	if (count < REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_CY);
		return (false);
	}
	if (!parse_cylinder_required(elements, &input))
	{
		return (false);
	}
	return (create_cylinder(&input));
}

static bool	parse_cylinder_required(\
	char const **elements, t_input_cylinder *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_DIAMETER, &(input->radius));
	fields[3] = build_required_field(REQUIRED_HALF_HEIGHT, \
		&(input->half_height));
	fields[4] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
