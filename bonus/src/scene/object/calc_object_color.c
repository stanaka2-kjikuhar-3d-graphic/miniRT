/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 22:54:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "object.h"
#include "color.h"
#include "vector.h"

#include "./object_private.h"

static bool	is_even_cell(t_vec2 uv, float checker_size, float u_per_v);

t_color	calc_object_color(t_object const *object, t_vec2 uv)
{
	if (object->material.pattern_type == PATTERN_CHECKER)
	{
		if (is_even_cell(uv, 0.25f, object->material.u_per_v))
			return (object->material.checker.color1);
		return (object->material.checker.color2);
	}
	else if (object->material.pattern_type == PATTERN_TEXTURE)
	{
		return (get_uv_pixel_color(object->material.texture, uv.u, uv.v));
	}
	return (object->material.albedo);
}

static bool	is_even_cell(t_vec2 uv, float checker_size, float u_per_v)
{
	t_ivec2	cell;

	cell.u = (int)floorf((uv.u * u_per_v) / checker_size);
	cell.v = (int)floorf(uv.v / checker_size);
	return ((cell.u + cell.v) % 2 == 0);
}
