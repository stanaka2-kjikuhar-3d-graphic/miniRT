/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light_setting.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 14:06:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"
#include "color.h"

#include "./parse_file_private.h"

bool	parse_ambient_light_setting(char const **elements)
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
	set_ambient_light(color, brightness);
	return (true);
}
