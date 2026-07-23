/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 23:02:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "config.h"
#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_sphere_required(\
				char const **elements, t_input_sphere *input);
static bool	parse_sphere_optional(\
				char const **optional_elements, t_input_sphere *input);
static void	set_default_sphere_option(t_input_sphere *input);

bool	parse_sphere(char const **elements)
{
	size_t			count;
	t_input_sphere	input;

	count = count_split(elements);
	if (count < 4)
	{
		print_error_hint(ERROR_SP_COUNT, HINT_SP);
		return (false);
	}
	if (!parse_sphere_required(elements, &input) \
		|| !parse_sphere_optional(elements + 4, &input))
	{
		return (false);
	}
	return (create_sphere(&input));
}

static bool	parse_sphere_required(\
	char const **elements, t_input_sphere *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->radius), parse_radius}, \
		{elements[3], &(input->albedo), parse_color}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(required_fields, required_count));
}

static bool	parse_sphere_optional(\
	char const **optional_elements, t_input_sphere *input)
{
	t_optional_field const	optional_fields[] = {\
		{"texture", &(input->option.texture), parse_texture}, \
		{"checker_color1", &(input->option.checker_color1), parse_color}, \
		{"checker_color2", &(input->option.checker_color2), parse_color}, \
		{"bump_map", &(input->option.bump_map), parse_texture}, \
		{"normal_map", &(input->option.normal_map), parse_texture}, \
		{"metalness", &(input->option.metalness), parse_metalness}, \
		{"shininess", &(input->option.shininess), parse_shininess}};
	size_t const			optional_count = sizeof(optional_fields) \
												/ sizeof(t_optional_field);

	set_default_sphere_option(input);
	if (!parse_optional_fields(\
			optional_elements, optional_fields, optional_count))
	{
		return (false);
	}
	input->option.pattern_type \
		= get_pattern_type(optional_elements);
	return (true);
}

static void	set_default_sphere_option(t_input_sphere *input)
{
	input->option.pattern_type = PATTERN_SOLID;
	input->option.texture = NULL;
	input->option.checker_color1 = (t_color){0.0f, 0.0f, 0.0f};
	input->option.checker_color2 = (t_color){1.0f, 1.0f, 1.0f};
	input->option.bump_map = NULL;
	input->option.normal_map = NULL;
	input->option.metalness = false;
	input->option.shininess = SHININESS;
}
