/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 20:24:05 by stanaka2         ###   ########.fr       */
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

static bool	parse_plane_pos(char const *element);
static bool	parse_plane_dir(char const *element);
static bool	parse_plane_color(char const *element);

bool	parse_plane_setting(char const **elements)
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
	if (!parse_plane_pos(elements[1]) \
		|| !parse_plane_dir(elements[2]) \
		|| !parse_plane_color(elements[3]))
	{
		return (false);
	}
	return (true);
}

static bool	parse_plane_pos(char const *element)
{
	t_dvec3	pos;

	if (!parse_dvec3(element, &pos))
		return (false);
	return (true);
}

static bool	parse_plane_dir(char const *element)
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

static bool	parse_plane_color(char const *element)
{
	int	color;

	if (!parse_color(element, &color))
		return (false);
	return (true);
}
