/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:53:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "camera.h"
#include "viewport.h"

#include "../parser_private.h"

static bool	parse_camera_required(char const **elements, \
				t_input_camera *camera, t_input_viewport *viewport);

bool	parse_camera(char const **elements)
{
	size_t				count;
	t_input_camera		camera;
	t_input_viewport	viewport;

	count = count_split(elements);
	if (count != 4)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_C);
		return (false);
	}
	if (!parse_camera_required(elements, &camera, &viewport))
		return (false);
	set_camera(&camera);
	set_viewport(&viewport);
	return (true);
}

static bool	parse_camera_required(char const **elements, \
	t_input_camera *camera, t_input_viewport *viewport)
{
	t_required_field		fields[3];
	size_t const			count = sizeof(fields) / sizeof(t_required_field);

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(camera->pos));
	fields[1] = build_required_field(REQUIRED_DIR, &(camera->dir));
	fields[2] = build_required_field(REQUIRED_FOV, &(viewport->fov));
	return (parse_required_fields(elements, fields, count));
}
