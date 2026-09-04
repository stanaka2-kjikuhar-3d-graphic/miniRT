/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 04:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/08 23:51:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 5

static bool	parse_spot_light_required(\
				char const **elements, t_input_spot_light *input);

bool	parse_spot_light(char const **elements)
{
	size_t				count;
	t_input_spot_light	input;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_SL);
		return (false);
	}
	if (!parse_spot_light_required(elements, &input))
		return (false);
	return (create_spot_light(&input));
}

static bool	parse_spot_light_required(\
	char const **elements, t_input_spot_light *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->pos));
	fields[1] = build_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->color));
	fields[3] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[4] = build_required_field(REQUIRED_ANGLE, &(input->outer_angle));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
