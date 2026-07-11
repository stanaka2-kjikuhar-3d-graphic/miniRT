/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:45:00 by stanaka2         ###   ########.fr       */
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

bool	parse_camera_setting(char const **elements)
{
	size_t				count;
	t_input_camera		camera;
	t_input_viewport	viewport;

	count = count_split(elements);
	if (count != 4)
	{
		print_error_hint(ERROR_C_COUNT, HINT_C);
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
	t_required_field const	required_fields[] = {\
		{elements[1], &(camera->pos), parse_coordinate}, \
		{elements[2], &(camera->dir), parse_dir}, \
		{elements[3], &(viewport->fov), parse_fov}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(required_fields, required_count))
		return (false);
	return (true);
}
