/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:38:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 04:23:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "object.h"
#include "vector.h"
#include "ray.h"

#include "../phong_private.h"

bool	phong_shading(t_hit const *hit, t_vec3 light_dir, float light_dist)
{
	float			offset;
	t_ray			shadow_ray;
	t_object const	*object;
	float			t;

	offset = SHADOW_EPSILON * fmaxf(1.0f, vec3_length(hit->point));
	shadow_ray.origin = vec3_add(hit->point, vec3_scale(offset, hit->normal));
	shadow_ray.dir = light_dir;
	object = NULL;
	while (get_next_object(&object))
	{
		t = intersect(object, &shadow_ray);
		if (t != t || t <= 0 || light_dist - EPSILON <= t)
			continue ;
		return (true);
	}
	return (false);
}
