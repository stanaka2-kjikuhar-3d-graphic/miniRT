/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:49:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

void	raytrace(t_ivec2 pixel)
{
	t_ray	ray;

	ray = calc_ray(pixel);
	put_color_to_window_image(pixel, trace_ray(ray, 0));
}
