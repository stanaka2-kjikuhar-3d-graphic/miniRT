/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_weights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:03:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/17 16:34:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "object.h"
#include "ray.h"

#include "./raytracer_private.h"

t_weights	calc_weights(t_ray const *ray, t_hit const *hit, int depth)
{
	t_material const *const	material = &(hit->object->material);

	if (depth >= MAX_RECURSION_DEPTH)
		return ((t_weights){.local = 1.0f});
	if (material->ior <= 0.0f)
		return ((t_weights){.local = 1.0f - material->reflectivity, \
			.reflected = material->reflectivity});
	if (calc_sin2_transmitted(ray, hit) > 1.0f)
		return ((t_weights){.reflected = 1.0f});
	return ((t_weights){.refracted = 1.0f});
}
