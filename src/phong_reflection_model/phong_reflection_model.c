/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 23:53:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "mlx.h"
#include "ft_mlx.h"
#include "vector.h"
#include "scene.h"
#include "ray.h"
#include "./phong_reflection_model_private.h"

t_ray	calc_ray(int x, int y);

void	phong_reflection_model(void)
{
	t_viewport const	*viewport;
	int					h;
	int					w;
	t_ray				ray;
	t_hit				hit;

	viewport = get_viewport();
	h = 0;
	while (h < viewport->pixel.height)
	{
		w = 0;
		while (w < viewport->pixel.width)
		{
			ray = calc_ray(w, h);
			hit = intersects(&ray);
			if (hit.object != NULL)
			{
				*get_pixel_addr(get_image(IMG_WINDOW), w, h) = hit.object->color;
			}
			++w;
		}
		++h;
	}
}

t_ray	calc_ray(int x, int y)
{
	t_ray				ray;
	t_camera const		*camera;
	t_viewport const	*viewport;
	double				tx;
	double				ty;

	camera = get_camera();
	viewport = get_viewport();
	tx = ((x + 0.5) / (viewport->pixel.width / 2.0)) - 1.0;
	ty = -(((y + 0.5) / (viewport->pixel.height / 2.0)) - 1.0);
	ray.dir = dvec3_normalize(\
				dvec3_add(camera->dir, \
				dvec3_add(\
					dvec3_scale(tx * viewport->half_width, camera->right), \
					dvec3_scale(ty * viewport->half_height, camera->up)\
				))\
			);
	ray.origin = camera->pos;
	return (ray);
}
