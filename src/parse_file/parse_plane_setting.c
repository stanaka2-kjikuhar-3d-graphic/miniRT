/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 14:42:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "./parse_file_private.h"

static bool	parse_plane(char const **elements);

bool	parse_plane_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 4)
		return (parse_plane(elements));
	else
	{
		print_error_hint(ERROR_PLANE_COUNT, HINT_PLANE);
		return (false);
	}
}

static bool	parse_plane(char const **elements)
{
	t_object	object;

	object.type = OBJ_PLANE;
	if (!parse_pos(elements[1], &(object.plane.pos)) \
		|| !parse_dir(elements[2], &(object.plane.normal)) \
		|| !parse_color(elements[3], &(object.plane.color)))
	{
		return (false);
	}
	if (!add_object(&object))
		return (false);
	return (true);
}
