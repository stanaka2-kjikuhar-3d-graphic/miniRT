/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:02:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:50:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_point_light_required(\
				char const **elements, t_input_point_light *input);

bool	parse_point_light(char const **elements)
{
	size_t				count;
	t_input_point_light	input;

	count = count_split(elements);
	if (count != 4)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_L);
		return (false);
	}
	if (!parse_point_light_required(elements, &input))
		return (false);
	return (create_point_light(&input));
}

static bool	parse_point_light_required(\
	char const **elements, t_input_point_light *input)
{
	t_required_field		fields[3];
	size_t const			count = sizeof(fields) / sizeof(t_required_field);

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->pos));
	fields[1] = build_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->color));
	return (parse_required_fields(elements, fields, count));
}
