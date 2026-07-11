/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot_light_setting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 04:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:45:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_spot_light_required(\
				char const **elements, t_input_spot_light *input);

bool	parse_spot_light_setting(char const **elements)
{
	size_t				count;
	t_input_spot_light	input;

	count = count_split(elements);
	if (count != 6)
	{
		print_error_hint(ERROR_SL_COUNT, HINT_SL);
		return (false);
	}
	if (!parse_spot_light_required(elements, &input))
		return (false);
	return (create_spot_light(&input));
}

static bool	parse_spot_light_required(\
	char const **elements, t_input_spot_light *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->pos), parse_coordinate}, \
		{elements[2], &(input->brightness), parse_brightness}, \
		{elements[3], &(input->color), parse_color}, \
		{elements[4], &(input->dir), parse_dir}, \
		{elements[5], &(input->outer_angle), parse_angle}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(required_fields, required_count));
}
