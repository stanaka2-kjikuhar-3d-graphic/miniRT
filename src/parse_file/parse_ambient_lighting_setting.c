/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_lighting_setting.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 00:12:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 13:32:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "scene.h"
#include "color.h"
#include "./parse_file_private.h"

bool	parse_ambient_lighting_setting(char const **elements)
{
	size_t	count;
	double	brightness;
	t_color	color;

	count = count_split(elements);
	if (count != 3)
	{
		if (count < 3)
			print_error_hint(ERROR_AMBIENT_FEW, HINT_AMBIENT);
		else
			print_error_hint(ERROR_AMBIENT_MANY, HINT_AMBIENT);
		return (false);
	}
	if (!parse_brightness(elements[1], &brightness) \
		|| !parse_color(elements[2], &color))
	{
		return (false);
	}
	set_ambient_lighting(color, brightness);
	return (true);
}
