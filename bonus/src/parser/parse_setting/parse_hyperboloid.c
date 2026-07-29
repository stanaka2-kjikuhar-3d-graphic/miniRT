/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hyperboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:37:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 11:42:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_hyperboloid_required(\
				char const **elements, t_input_hyperboloid *input);
static bool	parse_hyperboloid_optional(\
				char const **optional_elements, t_input_hyperboloid *input);

bool	parse_hyperboloid(char const **elements)
{
	size_t				count;
	t_input_hyperboloid	input;

	count = count_split(elements);
	if (count < 7)
	{
		print_line_error(ERROR_HB_COUNT, HINT_HB1 HINT_HB2);
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
	t_required_field const	fields[] = {\
		{elements[1], &(input->center), parse_coordinate}, \
		{elements[2], &(input->dir), parse_dir}, \
		{elements[3], &(input->center_radius), parse_radius}, \
		{elements[4], &(input->cap_radius), parse_radius}, \
		{elements[5], &(input->half_height), parse_half_height}, \
		{elements[6], &(input->albedo), parse_color}};
	size_t const			count = sizeof(fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(fields, count))
		return (false);
	set_error_line_multi_strs((char const *[]){elements[3], elements[4], NULL});
	if (input->center_radius >= input->cap_radius)
	{
		print_line_error(ERROR_HB_RADIUS, NULL);
		return (false);
	}
	return (true);
}

static bool	parse_hyperboloid_optional(\
	char const **optional_elements, t_input_hyperboloid *input)
{
	t_optional_field	fields[OPTIONAL_FIELD_COUNT];

	init_optional_fields(fields);
	bind_material_option(fields, &(input->option.material));
	if (!parse_optional_fields(optional_elements, fields))
		return (false);
	input->option.material.pattern_type \
		= get_pattern_type(optional_elements);
	input->option.material.normal_type \
		= get_normal_type(optional_elements);
	return (true);
}
