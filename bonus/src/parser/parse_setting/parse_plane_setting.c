/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:22:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:30:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_plane_required(\
				char const **elements, t_input_plane *input);
static bool	parse_plane_optional(\
				char const **optional_elements, t_input_plane *input);

bool	parse_plane_setting(char const **elements)
{
	size_t			count;
	t_input_plane	input;

	count = count_split(elements);
	if (count < 4)
	{
		print_error_hint(ERROR_PL_COUNT, HINT_PL);
		return (false);
	}
	init_material(&(input.material));
	input.material.uv_type = UV_PLANE;
	if (!parse_plane_required(elements, &input) \
		|| !parse_plane_optional(elements + 4, &input))
	{
		return (false);
	}
	return (create_plane(&input));
}

static bool	parse_plane_required(\
	char const **elements, t_input_plane *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->normal), parse_dir}, \
		{elements[3], &(input->material.albedo), parse_color}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(required_fields, required_count))
		return (false);
	return (true);
}

static bool	parse_plane_optional(\
	char const **optional_elements, t_input_plane *input)
{
	t_optional_field const	optional_fields[] = {\
		{"texture", &(input->material.texture), parse_texture}, \
		{"checker_color1", &(input->material.checker.color1), parse_color}, \
		{"checker_color2", &(input->material.checker.color2), parse_color}, \
		{"metalness", &(input->material.metalness), parse_metalness}, \
		{"shininess", &(input->material.shininess), parse_shininess}};
	size_t const			optional_count = sizeof(optional_fields) \
												/ sizeof(t_optional_field);

	if (!parse_optional_fields(\
			optional_elements, optional_fields, optional_count))
	{
		return (false);
	}
	input->material.pattern_type \
		= get_pattern_type(optional_elements);
	return (true);
}
