/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 21:04:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 19:56:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include "ray.h"
#include "vector.h"
#include "camera.h"
#include "viewport.h"
#include "config.h"

t_ray	calc_ray(t_ivec2 pixel, uint32_t *seed)
{
	t_ray				ray;
	t_camera const		*camera;
	t_viewport const	*viewport;
	t_vec2				t;

	camera = get_camera();
	viewport = get_viewport();
	t.x = (float)((((double)pixel.x \
			+ ft_xorshift_range(seed, 0.0f, 1.0f)) \
			/ ((double)WINDOW_WIDTH / 2.0)) \
			- 1.0);
	t.y = -(float)((((double)pixel.y \
			+ ft_xorshift_range(seed, 0.0f, 1.0f)) \
			/ ((double)WINDOW_HEIGHT / 2.0)) \
			- 1.0);
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
