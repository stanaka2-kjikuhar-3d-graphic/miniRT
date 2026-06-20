/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:03:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "view.h"

#include "./parse_file_private.h"

bool	parse_camera_setting(char const **elements)
{
	size_t	count;
	t_dvec3	pos;
	t_dvec3	dir;
	double	fov;

	count = count_split(elements);
	if (count != 4)
	{
		if (count < 4)
			print_error_hint(ERROR_CAMERA_FEW, HINT_CAMERA);
		else
			print_error_hint(ERROR_CAMERA_MANY, HINT_CAMERA);
		return (false);
	}
	if (!parse_pos(elements[1], &pos) \
		|| !parse_dir(elements[2], &dir) \
		|| !parse_fov(elements[3], &fov))
	{
		return (false);
	}
	set_camera_pos(pos);
	set_camera_dir(dir);
	set_viewport(fov);
	return (true);
}
