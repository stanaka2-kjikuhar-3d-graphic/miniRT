/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 18:37:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "view.h"

#include "./parse_file_private.h"

static bool	parse_camera(char const **elements);

bool	parse_camera_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 4)
		return (parse_camera(elements));
	else
	{
		print_error_hint(ERROR_CAMERA_COUNT, HINT_CAMERA);
		return (false);
	}
}

static bool	parse_camera(char const **elements)
{
	t_input_camera		camera;
	t_input_viewport	viewport;

	if (!parse_pos(elements[1], &(camera.pos)) \
		|| !parse_dir(elements[2], &(camera.dir)) \
		|| !parse_fov(elements[3], &(viewport.fov)))
	{
		return (false);
	}
	set_camera(&camera);
	set_viewport(&viewport);
	return (true);
}
