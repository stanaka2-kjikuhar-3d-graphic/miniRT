/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 18:02:19 by stanaka2         ###   ########.fr       */
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

void	phong(t_ivec2 pixel)
{
	t_ray	ray;
	t_hit	hit;

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
