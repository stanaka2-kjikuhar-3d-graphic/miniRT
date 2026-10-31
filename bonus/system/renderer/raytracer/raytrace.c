/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/31 21:22:40 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

void	raytrace(t_ivec2 pixel, t_vec2 sample)
{
	t_ray	ray;

	ray = calc_ray(sample);
	put_color_to_window_image(pixel, trace_ray(ray, 0));
}
