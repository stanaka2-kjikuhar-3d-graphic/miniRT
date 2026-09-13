/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:02:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 00:28:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "loader.h"
#include "light_loader.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 3

static bool	parse_point_light_required(\
				char const **elements, t_point_light_input *input);

bool	parse_point_light(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_L);
		return (false);
	}
	input->type = POINT_LIGHT_INPUT;
	if (!parse_point_light_required(elements, &(input->point_light)))
		return (false);
	return (true);
}

static bool	parse_point_light_required(\
	char const **elements, t_point_light_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->pos));
	fields[1] = build_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->color));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
