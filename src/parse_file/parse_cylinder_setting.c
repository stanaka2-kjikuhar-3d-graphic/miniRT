/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_setting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 18:37:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "./parse_file_private.h"

static bool	parse_cylinder(char const **elements);
static bool	add_cap_circles(t_cylinder *cylinder);

bool	parse_cylinder_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 6)
		return (parse_cylinder(elements));
	else
	{
		print_error_hint(ERROR_CYLINDER_COUNT, HINT_CYLINDER);
		return (false);
	}
}

static bool	parse_cylinder(char const **elements)
{
	t_object	object;

	object.type = OBJ_CYLINDER;
	if (!parse_pos(elements[1], &(object.cylinder.center)) \
		|| !parse_dir(elements[2], &(object.cylinder.dir)) \
		|| !parse_radius(elements[3], &(object.cylinder.radius)) \
		|| !parse_half_height(elements[4], &(object.cylinder.half_height)) \
		|| !parse_color(elements[5], &(object.cylinder.color)))
	{
		return (false);
	}
	if (!add_object(&object) || !add_cap_circles(&(object.cylinder)))
		return (false);
	return (true);
}

static bool	add_cap_circles(t_cylinder *cylinder)
{
	t_object	top;
	t_object	bottom;

	top.type = OBJ_CIRCLE;
	top.circle = (t_circle){\
		.color = cylinder->color, \
		.center = vec3_add(cylinder->center, \
			vec3_scale(cylinder->half_height, cylinder->dir)), \
		.normal = cylinder->dir, \
		.radius = cylinder->radius};
	if (!add_object(&top))
		return (false);
	bottom.type = OBJ_CIRCLE;
	bottom.circle = (t_circle){\
		.color = cylinder->color,
		.center = vec3_add(cylinder->center, \
			vec3_scale(-(cylinder->half_height), cylinder->dir)), \
		.normal = vec3_scale(-1, cylinder->dir), \
		.radius = cylinder->radius};
	if (!add_object(&bottom))
		return (false);
	return (true);
}
