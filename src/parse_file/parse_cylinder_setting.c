/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_setting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:04:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "./parse_file_private.h"

static bool	add_cap_circles(t_cylinder *cylinder);

bool	parse_cylinder_setting(char const **elements)
{
	size_t		count;
	t_object	object;

	count = count_split(elements);
	if (count != 6)
	{
		if (count < 6)
			print_error_hint(ERROR_CYLINDER_FEW, HINT_CYLINDER);
		else
			print_error_hint(ERROR_CYLINDER_MANY, HINT_CYLINDER);
		return (false);
	}
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
		.center = dvec3_add(cylinder->center, \
			dvec3_scale(cylinder->half_height, cylinder->dir)), \
		.normal = cylinder->dir, \
		.radius = cylinder->radius};
	if (!add_object(&top))
		return (false);
	bottom.type = OBJ_CIRCLE;
	bottom.circle = (t_circle){\
		.color = cylinder->color,
		.center = dvec3_add(cylinder->center, \
			dvec3_scale(-(cylinder->half_height), cylinder->dir)), \
		.normal = dvec3_scale(-1, cylinder->dir), \
		.radius = cylinder->radius};
	if (!add_object(&bottom))
		return (false);
	return (true);
}
