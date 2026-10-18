/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 16:50:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "mlx.h"

#include "vector.h"
#include "camera.h"
#include "viewport.h"
#include "ray.h"
#include "color.h"
#include "vector.h"

#include "./renderer_private.h"

void	phong(t_ivec2 pixel)
{
	t_ray	ray;
	t_hit	hit;
	t_color	pixel_color;

	ray = calc_ray(pixel);
	hit = find_closest_hit(&ray);
	if (hit.object != NULL)
	{
		set_hit_record(&ray, &hit);
		pixel_color = phong_lighting(&ray, &hit);
	}
	else
		pixel_color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	put_color_to_window_image(pixel, pixel_color);
}
