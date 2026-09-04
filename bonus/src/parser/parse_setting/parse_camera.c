/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/04 22:00:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "camera.h"
#include "viewport.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 3

static bool	parse_camera_required(char const **elements, t_input_camera *input);

bool	parse_camera(char const **elements)
{
	size_t			count;
	t_input_camera	input;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_C);
		return (false);
	}
	if (!parse_camera_required(elements, &input))
		return (false);
	set_camera(&input);
	return (true);
}

static bool	parse_camera_required(char const **elements, t_input_camera *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->pos));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_FOV, &(input->fov));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
