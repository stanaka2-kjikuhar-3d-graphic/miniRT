/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 20:24:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "./parse_file_private.h"

static bool	parse_sphere_pos(char const *element);
static bool	parse_sphere_diameter(char const *element);
static bool	parse_sphere_color(char const *element);

bool	parse_sphere_setting(char const **elements)
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
	if (!parse_sphere_pos(elements[1]) \
		|| !parse_sphere_diameter(elements[2]) \
		|| !parse_sphere_color(elements[3]))
	{
		return (false);
	}
	return (true);
}

static bool	parse_sphere_pos(char const *element)
{
	t_dvec3	pos;

	if (!parse_dvec3(element, &pos))
		return (false);
	return (true);
}

static bool	parse_sphere_diameter(char const *element)
{
	double	diameter;

	if (!parse_double(element, &diameter))
		return (false);
	if (diameter <= 0.0)
	{
		print_error("");
		return (false);
	}
	return (true);
}

static bool	parse_sphere_color(char const *element)
{
	int	color;

	if (!parse_color(element, &color))
		return (false);
	return (true);
}
