/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:11:45 by stanaka2         ###   ########.fr       */
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
		t = intersect(object, ray);
		if (EPSILON < t && t < hit.t)
		{
			hit.object = object;
			hit.t = t;
		}
	}
	if (hit.object == NULL)
		return (hit);
	hit.point = vec3_add(ray->origin, vec3_scale(hit.t, ray->dir));
	hit.normal = calc_normal(hit.object, ray, hit.point);
	hit.color = get_object_color(hit.object);
	return (hit);
}
