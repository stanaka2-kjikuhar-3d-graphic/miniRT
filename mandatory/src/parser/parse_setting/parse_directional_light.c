/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_directional_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:58:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/08 23:52:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 3

static bool	parse_directional_light_required(\
				char const **elements, t_input_directional_light *input);

bool	parse_directional_light(char const **elements)
{
	size_t						count;
	t_input_directional_light	input;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_DL);
		return (false);
	}
	if (!parse_directional_light_required(elements, &input))
		return (false);
	return (create_directional_light(&input));
}

static bool	parse_directional_light_required(\
	char const **elements, t_input_directional_light *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[1] = build_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->color));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
