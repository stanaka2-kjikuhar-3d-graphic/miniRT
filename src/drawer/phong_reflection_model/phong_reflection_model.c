/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 17:17:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "vector.h"
#include "view.h"
#include "ray.h"
#include "color.h"

#include "./phong_reflection_model_private.h"

static t_ray	calc_ray(t_ivec2 pixel);
static void		put_color(t_color color, t_ivec2 pixel);

void	phong_reflection_model(void)
{
	t_viewport const	*viewport;
	t_ivec2				pixel;
	t_ray				ray;
	t_hit				hit;

	viewport = get_viewport();
	pixel.y = 0;
	while (pixel.y < viewport->pixel_size.height)
	{
		pixel.x = 0;
		while (pixel.x < viewport->pixel_size.width)
		{
			ray = calc_ray(pixel);
			hit = intersection(&ray);
			if (hit.object != NULL)
				put_color(lighting(&ray, &hit), pixel);
			else
				put_color((t_color){.r = 0.0, .g = 0.0, .b = 0.0}, pixel);
			++(pixel.x);
		}
		++(pixel.y);
	}
}

static t_ray	calc_ray(t_ivec2 pixel)
{
	t_ray				ray;
	t_camera const		*camera;
	t_viewport const	*viewport;
	t_dvec2				t;

	camera = get_camera();
	viewport = get_viewport();
	t.x = ((pixel.x + 0.5) / viewport->pixel_half_size.width) - 1.0;
	t.y = -(((pixel.y + 0.5) / viewport->pixel_half_size.height) - 1.0);
	ray.dir = dvec3_normalize(\
				dvec3_add(camera->dir, \
				dvec3_add(\
					dvec3_scale(t.x * viewport->world_half_size.width, \
									camera->right), \
					dvec3_scale(t.y * viewport->world_half_size.height, \
									camera->up) \
				)) \
			);
	ray.origin = camera->pos;
	return (ray);
}

static void	put_color(t_color color, t_ivec2 pixel)
{
	*get_pixel_addr(get_image(IMG_WINDOW), pixel.x, pixel.y) = calc_rgb(color);
}
