/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:56:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 3

static bool	parse_plane_required(\
				char const **elements, t_input_plane *input);

bool	parse_plane(char const **elements)
{
	size_t			count;
	t_input_plane	input;

	count = count_split(elements);
	if (count < REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_PL);
		return (false);
	}
	if (!parse_plane_required(elements, &input))
	{
		return (false);
	}
	return (create_plane(&input));
}

static bool	parse_plane_required(\
	char const **elements, t_input_plane *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_NORMAL, &(input->normal));
	fields[2] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}
