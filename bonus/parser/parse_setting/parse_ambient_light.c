/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:43:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "logger.h"
#include "loader.h"
#include "loader_light.h"

#include "./parse_setting_private.h"

#define REQUIRED_COUNT 2

static bool	parse_ambient_light_required(\
				char const **elements, t_ambient_light_input *input);

bool	parse_ambient_light(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_log_line(LOG_ERROR, ERROR_FIELDS_COUNT);
		print_log_hint(LOG_ERROR, HINT_A);
		return (false);
	}
	input->type = AMBIENT_LIGHT_INPUT;
	if (!parse_ambient_light_required(elements, &(input->ambient_light)))
		return (false);
	return (true);
}

static bool	parse_ambient_light_required(\
	char const **elements, t_ambient_light_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = bind_required_field(REQUIRED_BRIGHTNESS, &(input->brightness));
	fields[1] = bind_required_field(REQUIRED_COLOR, &(input->color));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
