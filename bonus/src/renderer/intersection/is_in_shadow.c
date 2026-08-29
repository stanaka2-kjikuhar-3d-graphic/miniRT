/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:27:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 17:37:15 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "object.h"
#include "vector.h"
#include "ray.h"

#include "./intersection.h"

bool	is_in_shadow(t_hit const *hit, t_vec3 light_dir, float light_dist)
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
		t = calc_object_intersection(object, &shadow_ray);
		if (t != t || t <= 0.0f || light_dist - EPSILON <= t)
			continue ;
		return (true);
	}
	return (false);
}
