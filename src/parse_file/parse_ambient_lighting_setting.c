/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_lighting_setting.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 00:12:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 20:11:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "./parse_file_private.h"

static bool	parse_ambient_lighting_brightness(char const *element);
static bool	parse_ambient_lighting_color(char const *element);

bool	parse_ambient_lighting_setting(char const **elements)
{
	if (elements[1] == NULL || elements[2] == NULL || elements[3] != NULL)
	{
		if (elements[1] == NULL || elements[2] == NULL)
			print_error("");
		else
			print_error("");
		return (false);
	}
	if (!parse_ambient_lighting_brightness(elements[1]) \
		|| !parse_ambient_lighting_color(elements[2]))
	{
		return (false);
	}
	return (true);
}

static bool	parse_ambient_lighting_brightness(char const *element)
{
	double	brightness;

	if (!parse_double(element, &brightness))
		return (false);
	if (brightness < 0.0 || 1.0 < brightness)
	{
		print_error("");
		return (false);
	}
	return (true);
}

static bool	parse_ambient_lighting_color(char const *element)
{
	int	color;

	if (!parse_color(element, &color))
		return (false);
	return (true);
}
