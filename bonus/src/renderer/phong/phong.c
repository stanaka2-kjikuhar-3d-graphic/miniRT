/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/10 21:30:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "vector.h"
#include "camera.h"
#include "viewport.h"
#include "ray.h"
#include "color.h"

#include "./phong_private.h"
#include "../renderer_private.h"

static t_ray	calc_ray(t_ivec2 pixel);

void	phong(t_ivec2 pixel)
{
	t_ray				ray;
	t_hit				hit;

	ray = calc_ray(pixel);
	hit = find_closest_hit(&ray);
	if (hit.object != NULL)
		put_color_to_window_image(pixel, phong_lighting(&ray, &hit));
	else
	{
		put_color_to_window_image(pixel, \
			(t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	}
}

static t_ray	calc_ray(t_ivec2 pixel)
{
	t_ray				ray;
	t_camera const		*camera;
	t_viewport const	*viewport;
	t_vec2				t;

	camera = get_camera();
	viewport = get_viewport();
	t.x = (((float)(pixel.x) + 0.5f) / viewport->pixel_half_size.width) - 1.0f;
	t.y = -((((float)(pixel.y) + 0.5f) / viewport->pixel_half_size.height) \
				- 1.0f);
	ray.dir = vec3_normalize(\
				vec3_add(camera->dir, \
				vec3_add(\
					vec3_scale(t.x * viewport->world_half_size.width, \
									camera->right), \
					vec3_scale(t.y * viewport->world_half_size.height, \
									camera->up) \
				)) \
			);
	ray.origin = camera->pos;
	return (ray);
}
