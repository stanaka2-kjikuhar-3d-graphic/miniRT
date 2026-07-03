/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 19:50:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "object.h"
#include "ray.h"

#include "./phong_private.h"

t_hit	intersection(t_ray const *ray)
{
	t_object const	*object;
	t_hit			hit;
	float			t;

	hit.object = NULL;
	hit.t = INFINITY;
	object = NULL;
	while (get_next_object(&object))
	{
		t = calc_object_intersection(object, ray);
		if (EPSILON < t && t < hit.t)
		{
			hit.object = object;
			hit.t = t;
		}
	}
	if (hit.object == NULL)
		return (hit);
	hit.point = vec3_add(ray->origin, vec3_scale(hit.t, ray->dir));
	hit.uv = calc_object_uv(hit.object, hit.point);
	hit.color = calc_object_color(hit.object, hit.uv);
	hit.normal = calc_object_normal(hit.object, ray, hit.point);
	return (hit);
}
