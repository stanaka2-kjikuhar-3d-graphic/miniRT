/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 00:23:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "loader.h"
#include "camera_loader.h"
#include "viewport.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 3

static bool	parse_camera_required(char const **elements, t_camera_input *input);

bool	parse_camera(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count != REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_C);
		return (false);
	}
	input->type = CAMERA_INPUT;
	if (!parse_camera_required(elements, &(input->camera)))
		return (false);
	return (true);
}

static bool	parse_camera_required(char const **elements, t_camera_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->pos));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_FOV, &(input->fov));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
