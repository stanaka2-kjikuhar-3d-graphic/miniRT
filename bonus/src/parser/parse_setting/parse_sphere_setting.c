/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 01:17:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_sphere(char const **elements);

bool	parse_sphere_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 4)
		return (parse_sphere(elements));
	else
	{
		print_error_hint(ERROR_SPHERE_COUNT, HINT_SPHERE);
		return (false);
	}
}

static bool	parse_sphere(char const **elements)
{
	t_input_sphere	input;

	if (!parse_pos(elements[1], &(input.center)) \
		|| !parse_radius(elements[2], &(input.radius)) \
		|| !parse_color(elements[3], &(input.color)))
	{
		return (false);
	}
	return (add_sphere(&input));
}
