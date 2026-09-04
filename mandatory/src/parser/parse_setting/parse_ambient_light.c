/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/08 23:50:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 2

static bool	parse_ambient_light_required(\
				char const **elements, t_input_ambient_light *input);

bool	parse_ambient_light(char const **elements)
{
	size_t					count;
	t_input_ambient_light	input;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_A);
		return (false);
	}
	if (!parse_ambient_light_required(elements, &input))
		return (false);
	create_ambient_light(&input);
	return (true);
}

static bool	parse_ambient_light_required(\
	char const **elements, t_input_ambient_light *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[1] = build_required_field(REQUIRED_COLOR, &(input->color));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
