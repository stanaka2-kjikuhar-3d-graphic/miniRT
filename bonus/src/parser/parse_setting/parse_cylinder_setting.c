/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_setting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 21:18:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_cylinder(char const **elements);

bool	parse_cylinder_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count < 6)
	{
		print_error_hint(ERROR_CY_COUNT, HINT_CY);
		return (false);
	}
	return (parse_cylinder(elements));
}

static bool	parse_cylinder(char const **elements)
{
	t_input_cylinder	input;
	float				cap_ratio;

	init_material(&(input.material));
	input.material.uv_type = UV_CYLINDER;
	if (!parse_coordinate(elements[1], &(input.center)) \
		|| !parse_dir(elements[2], &(input.dir)) \
		|| !parse_radius(elements[3], &(input.radius)) \
		|| !parse_half_height(elements[4], &(input.half_height)) \
		|| !parse_color(elements[5], &(input.material.albedo)) \
		|| !parse_material_options(elements + 6, &(input.material)))
	{
		return (false);
	}
	input.material.u_per_v = (float)(2.0f * M_PI * input.radius) \
				/ (2.0f * (input.radius + input.half_height));
	input.material.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input.radius / (2.0f * (input.radius + input.half_height));
	input.material.v_range = (t_range){\
		.min = cap_ratio, \
		.max = 1.0f - cap_ratio \
	};
	return (create_cylinder(&input));
}
