/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:40:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "object.h"
#include "color.h"
#include "vector.h"

#include "./object_private.h"

static bool	is_even_cell(t_vec2 uv, t_vec2 size);

t_color	calc_object_color(t_object const *object, t_vec2 uv)
{
	if (object->material.pattern_type == PATTERN_CHECKER)
	{
		if (is_even_cell(uv, object->uv.checker_size))
			return (object->material.checker.color1);
		return (object->material.checker.color2);
	}
	else if (object->material.pattern_type == PATTERN_TEXTURE)
	{
		return (decode_color(\
					*get_uv_pixel_addr(object->material.texture, uv)));
	}
	return (object->material.albedo);
}

static bool	is_even_cell(t_vec2 uv, t_vec2 checker_size)
{
	t_ivec2	cell;

	cell.u = (int)floorf(uv.u / checker_size.u);
	cell.v = (int)floorf(uv.v / checker_size.v);
	return ((cell.u + cell.v) % 2 == 0);
}
