/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:09:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 20:16:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
#include <unicode/utypes.h>
#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "./parse_file_private.h"

static bool	parse_camera_pos(char const *element);
static bool	parse_camera_dir(char const *element);
static bool	parse_camera_fov(char const *element);

bool	parse_camera_setting(char const **elements)
{
	if (elements[1] == NULL || elements[2] == NULL || elements[3] == NULL \
		|| elements[4] != NULL)
	{
		if (elements[1] == NULL || elements[2] == NULL || elements[3] == NULL)
			print_error("");
		else
			print_error("");
		return (false);
	}
	if (!parse_camera_pos(elements[1]) \
		|| !parse_camera_dir(elements[2]) \
		|| !parse_camera_fov(elements[3]))
	{
		return (false);
	}
	return (true);
}

static bool	parse_camera_pos(char const *element)
{
	t_dvec3	pos;

	if (!parse_dvec3(element, &pos))
		return (false);
	return (true);
}

static bool	parse_camera_dir(char const *element)
{
	t_dvec3	dir;
	double	length;

	if (!parse_dvec3(element, &dir))
		return (false);
	length = dvec3_length(dir);
	if (length < 1.0 - DBL_EPSILON || 1.0 + DBL_EPSILON < length)
	{
		print_error("");
		return (false);
	}
	return (true);
}

static bool	parse_camera_fov(char const *element)
{
	double	fov;

	if (!parse_double(element, &fov))
		return (false);
	if (fov <= 0.0 || 180.0 <= fov)
	{
		print_error("");
		return (false);
	}
	return (true);
}