/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/06 03:21:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_sphere(char const **elements);

bool	parse_sphere_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count < 4)
	{
		print_error_hint(ERROR_SP_COUNT, HINT_SP);
		return (false);
	}
	return (parse_sphere(elements));
}

static bool	parse_sphere(char const **elements)
{
	t_input_sphere	input;

	init_material(&(input.material));
	input.material.uv_type = UV_SPHERE;
	if (!parse_coordinate(elements[1], &(input.center)) \
		|| !parse_radius(elements[2], &(input.radius)) \
		|| !parse_color(elements[3], &(input.material.albedo)) \
		|| !parse_material_options(elements + 4, &(input.material)))
	{
		return (false);
	}
	return (create_sphere(&input));
}
