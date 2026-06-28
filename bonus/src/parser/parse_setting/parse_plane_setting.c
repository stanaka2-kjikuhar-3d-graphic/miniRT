/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:26:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_string.h"

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_plane(char const **elements);

bool	parse_plane_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 4)
	{
		print_error_hint(ERROR_PL_COUNT, HINT_PL);
		return (false);
	}
	return (parse_plane(elements));
}

static bool	parse_plane(char const **elements)
{
	t_input_plane	input;

	ft_bzero(&(input.material), sizeof(t_material));
	input.material.pattern_type = PATTERN_SOLID;
	if (!parse_pos(elements[1], &(input.center)) \
		|| !parse_dir(elements[2], &(input.normal)) \
		|| !parse_color(elements[3], &(input.material.albedo)))
	{
		return (false);
	}
	return (create_plane(&input));
}
