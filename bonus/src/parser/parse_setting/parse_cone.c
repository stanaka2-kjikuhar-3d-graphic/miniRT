/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 00:25:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "loader.h"
#include "object_loader.h"
#include "ft_error.h"

#include "../parser_private.h"

#define REQUIRED_COUNT 5

static bool	parse_cone_required(\
				char const **elements, t_cone_input *input);
static bool	parse_cone_optional(\
				char const **optional_elements, t_cone_input *input);

bool	parse_cone(char const **elements, t_scene_input *input)
{
	size_t	count;

	count = count_split(elements);
	if (count < REQUIRED_COUNT)
	{
		print_line_error(ERROR_FIELDS_COUNT, HINT_CO);
		return (false);
	}
	input->type = CONE_INPUT;
	if (!parse_cone_required(elements, &(input->cone)) \
		|| !parse_cone_optional(elements + REQUIRED_COUNT, &(input->cone)))
	{
		return (false);
	}
	return (true);
}

static bool	parse_cone_required(\
	char const **elements, t_cone_input *input)
{
	t_required_field	fields[REQUIRED_COUNT];

	fields[0] = build_required_field(REQUIRED_COORDINATE, &(input->center));
	fields[1] = build_required_field(REQUIRED_DIR, &(input->dir));
	fields[2] = build_required_field(REQUIRED_DIAMETER, &(input->radius));
	fields[3] = build_required_field(REQUIRED_HEIGHT, &(input->height));
	fields[4] = build_required_field(REQUIRED_COLOR, &(input->albedo));
	return (parse_required_fields(elements, fields, REQUIRED_COUNT));
}

static bool	parse_cone_optional(\
	char const **optional_elements, t_cone_input *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option_input(fields, &(input->option.material));
	fields[OPTIONAL_CHECKER_COUNT_U_EVEN].value \
		= &(input->option.checker_count.u);
	fields[OPTIONAL_CHECKER_COUNT_V].value = &(input->option.checker_count.v);
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	input->option.material.normal_type \
		= get_normal_type(optional_elements);
	return (true);
}
