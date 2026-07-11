/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light_setting.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:45:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_ambient_light_required(\
				char const **elements, t_input_ambient_light *input);

bool	parse_ambient_light_setting(char const **elements)
{
	size_t					count;
	t_input_ambient_light	input;

	count = count_split(elements);
	if (count != 3)
	{
		print_error_hint(ERROR_A_COUNT, HINT_A);
		return (false);
	}
	if (!parse_ambient_light_required(elements, &input))
		return (false);
	create_ambient_light(&input);
	return (true);
}

static bool	parse_ambient_light_required(\
	char const **elements, t_input_ambient_light *input)
{
	t_required_field const	required_fields[] = {\
		{elements[1], &(input->brightness), parse_brightness}, \
		{elements[2], &(input->color), parse_color}};
	size_t const			required_count = sizeof(required_fields) \
												/ sizeof(t_required_field);

	return (parse_required_fields(required_fields, required_count));
}
