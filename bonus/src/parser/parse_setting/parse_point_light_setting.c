/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point_light_setting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:02:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:45:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_point_light_required(\
				char const **elements, t_input_point_light *input);

bool	parse_point_light_setting(char const **elements)
{
	size_t				count;
	t_input_point_light	input;

	count = count_split(elements);
	if (count != 4)
	{
		print_error_hint(ERROR_L_COUNT, HINT_L);
		return (false);
	}
	if (!parse_point_light_required(elements, &input))
		return (false);
	return (create_point_light(&input));
}

static bool	parse_point_light_required(\
	char const **elements, t_input_point_light *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->pos), parse_coordinate}, \
		{elements[2], &(input->brightness), parse_brightness}, \
		{elements[3], &(input->color), parse_color}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	if (!parse_required_fields(required_fields, required_count))
		return (false);
	return (true);
}
