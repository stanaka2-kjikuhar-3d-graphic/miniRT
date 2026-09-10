/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:38:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 23:18:06 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "viewport.h"
#include "vector.h"
#include "ray.h"

#include "./renderer_private.h"

t_ray	calc_camera_ray(t_ivec2 pixel)
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
