/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:04:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/06 22:57:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_math.h"

#include "ray.h"
#include "vector.h"
#include "camera.h"
#include "viewport.h"
#include "config.h"

#include "../renderer_private.h"

static t_vec2	get_ray_target(t_ivec2 pixel, uint32_t *seed);

t_ray	calc_ray(t_ivec2 pixel, uint32_t *seed)
{
	t_ray				ray;
	t_camera const		*camera;
	t_viewport const	*viewport;
	t_vec2				t;

	camera = get_camera();
	viewport = get_viewport();
	t = get_ray_target(pixel, seed);
	ray.dir = vec3_normalize(\
				vec3_add(camera->dir, \
				vec3_add(\
					vec3_scale(t.x * viewport->half_size.width, camera->right), \
					vec3_scale(t.y * viewport->half_size.height, camera->up) \
				)) \
			);
	ray.origin = camera->pos;
	return (ray);
}

static t_vec2	get_ray_target(t_ivec2 pixel, uint32_t *seed)
{
	t_vec2	t;

	if (get_buffering_mode() == BUFFERING_OVERWRITE)
	{
		t.x = (float)((((double)pixel.x \
				+ 0.5) \
				/ ((double)WINDOW_WIDTH / 2.0)) \
				- 1.0);
		t.y = -(float)((((double)pixel.y \
				+ 0.5) \
				/ ((double)WINDOW_HEIGHT / 2.0)) \
				- 1.0);
	}
	else
	{
		t.x = (float)((((double)pixel.x \
				+ ft_xorshift_range(seed, 0.0f, 1.0f)) \
				/ ((double)WINDOW_WIDTH / 2.0)) \
				- 1.0);
		t.y = -(float)((((double)pixel.y \
				+ ft_xorshift_range(seed, 0.0f, 1.0f)) \
				/ ((double)WINDOW_HEIGHT / 2.0)) \
				- 1.0);
	}
	return (t);
}
