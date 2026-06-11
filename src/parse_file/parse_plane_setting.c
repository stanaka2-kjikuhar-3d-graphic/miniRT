/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 00:53:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"
#include "./parse_file_private.h"

bool	parse_plane_setting(char const **elements)
{
	size_t		count;
	t_object	object;

	count = count_splitted(elements);
	if (count != 4)
	{
		if (count < 4)
			print_error("");
		else
			print_error("");
		return (false);
	}
	object.type = OBJ_PLANE;
	if (!parse_pos(elements[1], &(object.plane.pos)) \
		|| !parse_dir(elements[2], &(object.plane.dir)) \
		|| !parse_color(elements[3], &(object.color)))
	{
		return (false);
	}
	if (!add_object(&object))
		return (false);
	return (true);
}
