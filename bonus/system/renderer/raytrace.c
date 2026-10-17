/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:40:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/17 16:31:22 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./renderer_private.h"
#include "./raytracer/raytracer_private.h"

void	raytrace(t_ivec2 pixel)
{
	t_ray	ray;

	ray = calc_ray(pixel);
	put_color_to_window_image(pixel, trace_ray(ray, 0));
}
