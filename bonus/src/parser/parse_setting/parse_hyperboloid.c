/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:38:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "config.h"
#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_hyperboloid_required(\
				char const **elements, t_input_hyperboloid *input);
static bool	parse_hyperboloid_optional(\
				char const **optional_elements, t_input_hyperboloid *input);
static void	set_default_hyperboloid_option(t_input_hyperboloid *input);

bool	parse_hyperboloid(char const **elements)
{
	size_t				count;
	t_input_hyperboloid	input;

	count = count_split(elements);
	if (count < 7)
	{
		print_line_error_hint(ERROR_HB_COUNT, HINT_HB1 HINT_HB2);
		return (false);
	}
	if (!parse_hyperboloid_required(elements, &input) \
		|| !parse_hyperboloid_optional(elements + 7, &input))
	{
		return (false);
	}
	return (create_hyperboloid(&input));
}

static bool	parse_hyperboloid_required(\
	char const **elements, t_input_hyperboloid *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->dir), parse_dir}, \
		{elements[3], &(input->center_radius), parse_radius}, \
		{elements[4], &(input->cap_radius), parse_radius}, \
		{elements[5], &(input->half_height), parse_half_height}, \
		{elements[6], &(input->albedo), parse_color}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(required_fields, required_count))
		return (false);
	set_error_line_multi_str((char const *[]){elements[3], elements[4], NULL});
	if (input->center_radius >= input->cap_radius)
	{
		print_line_error(ERROR_HB_RADIUS);
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_optional(\
	char const **optional_elements, t_input_hyperboloid *input)
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

	set_default_hyperboloid_option(input);
	if (!parse_optional_fields(\
			optional_elements, optional_fields, optional_count))
	{
		return (false);
	}
	input->option.pattern_type \
		= get_pattern_type(optional_elements);
	return (true);
}

static void	set_default_hyperboloid_option(t_input_hyperboloid *input)
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
