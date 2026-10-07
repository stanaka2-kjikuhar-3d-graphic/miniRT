/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:40:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 23:25:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

void	raytrace_pixel(t_ivec2 pixel)
{
	t_ray	ray;
	t_color	color;

	ray = calc_camera_ray(pixel);
	color = trace_ray(ray, 0);
	put_color_to_window_image(pixel, color);
}
