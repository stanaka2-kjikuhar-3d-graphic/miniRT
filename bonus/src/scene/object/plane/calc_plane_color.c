/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:16:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 19:29:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "color.h"

static t_color	calc_plane_checker_color(t_plane const *plane, t_vec2 uv);
static t_color	calc_plane_texture_color(t_plane const *plane, t_vec2 uv);

t_color	calc_plane_color(t_plane const *plane, t_vec2 uv)
{
	if (plane->material.pattern_type == PATTERN_CHECKER)
		return (calc_plane_checker_color(plane, uv));
	else if (plane->material.pattern_type == PATTERN_TEXTURE)
		return (calc_plane_texture_color(plane, uv));
	return (plane->material.albedo);
}

static t_color	calc_plane_checker_color(t_plane const *plane, t_vec2 uv)
{
	if (fmodf(floorf(uv.u / 1.0f) + floorf(uv.v / 1.0f), 2.0f) != 0.0f)
		return (plane->material.checker.color2);
	return (plane->material.checker.color1);
}

static t_color	calc_plane_texture_color(t_plane const *plane, t_vec2 uv)
{
	t_ivec2	cell;

	uv.u = uv.u / 1.0f - 0.5f;
	uv.v = uv.v / 1.0f - 0.5f;
	uv.u -= floorf(uv.u);
	uv.v -= floorf(uv.v);
	cell.u = (int)roundf(\
			(float)(plane->material.texture->width) * uv.u);
	cell.v = (int)roundf(\
			(float)(plane->material.texture->height) * uv.v);
	if (cell.u >= plane->material.texture->width)
		cell.u = plane->material.texture->width - 1;
	if (cell.v >= plane->material.texture->height)
		cell.v = plane->material.texture->height - 1;
	return (convert_uint_to_color(\
				*get_pixel_addr(plane->material.texture, cell.u, cell.v)));
}
