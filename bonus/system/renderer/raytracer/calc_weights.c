/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_weights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:03:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:44:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "ray.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

t_weights	calc_weights(t_ray const *ray, t_hit const *hit, int depth)
{
	if (depth >= MAX_RECURSION_DEPTH)
		return ((t_weights){.local = 1.0f});
	if (hit->material->ior <= 0.0f)
		return ((t_weights){.local = 1.0f - hit->material->reflectivity, \
			.reflected = hit->material->reflectivity});
	if (calc_sin2_transmitted(ray, hit) > 1.0f)
		return ((t_weights){.reflected = 1.0f});
	return ((t_weights){.refracted = 1.0f});
}
