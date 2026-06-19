/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:02:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:04:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "light.h"

#include "./parse_file_private.h"

bool	parse_light_setting(char const **elements)
{
	size_t	count;
	t_dvec3	pos;
	double	brightness;
	t_color	color;

	count = count_split(elements);
	if (count != 4)
	{
		if (count < 4)
			print_error_hint(ERROR_LIGHT_FEW, HINT_LIGHT);
		else
			print_error_hint(ERROR_LIGHT_MANY, HINT_LIGHT);
		return (false);
	}
	if (!parse_pos(elements[1], &pos) \
		|| !parse_brightness(elements[2], &brightness) \
		|| !parse_color(elements[3], &color))
	{
		return (false);
	}
	if (!add_light(pos, color, brightness))
		return (false);
	return (true);
}
