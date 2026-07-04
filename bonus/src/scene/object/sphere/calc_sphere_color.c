/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:20:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/04 17:58:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "color.h"

static t_color	calc_sphere_checker_color(t_sphere const *sphere, t_vec2 uv);
static t_color	calc_sphere_texture_color(t_sphere const *sphere, t_vec2 uv);

t_color	calc_sphere_color(t_sphere const *sphere, t_vec2 uv)
{
	if (sphere->material.pattern_type == PATTERN_CHECKER)
		return (calc_sphere_checker_color(sphere, uv));
	else if (sphere->material.pattern_type == PATTERN_TEXTURE)
		return (calc_sphere_texture_color(sphere, uv));
	return (sphere->material.albedo);
}

static t_color	calc_sphere_checker_color(t_sphere const *sphere, t_vec2 uv)
{
	if (fmodf(floorf(uv.u * (4.0f * 2.0f)) + floorf(uv.v * 4.0f), 2.0f) != 0.0f)
		return (sphere->material.checker.color2);
	return (sphere->material.checker.color1);
}

static t_color	calc_sphere_texture_color(t_sphere const *sphere, t_vec2 uv)
{
	t_ivec2	cell;

	cell.u = (int)((float)sphere->material.texture->width * uv.u);
	cell.v = (int)((float)sphere->material.texture->height * (1.0f - uv.v));
	if (cell.u >= sphere->material.texture->width)
		cell.u = sphere->material.texture->width - 1;
	if (cell.v >= sphere->material.texture->height)
		cell.v = sphere->material.texture->height - 1;
	return (convert_uint_to_color(\
				*get_pixel_addr(sphere->material.texture, cell.u, cell.v)));
}
