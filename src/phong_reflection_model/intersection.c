/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 15:35:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "ray.h"
#include "./phong_reflection_model_private.h"

t_hit	intersection(t_ray const *ray)
{
	t_object const *const	objects = get_objects();
	size_t const			count = get_objects_count();
	t_hit					hit;
	size_t					i;
	double					t;

	hit.object = NULL;
	hit.t = INFINITY;
	i = 0;
	while (i < count)
	{
		t = intersect(&(objects[i]), ray);
		if (hit.t > t)
		{
			hit.object = &(objects[i]);
			hit.t = t;
		}
		++i;
	}
	if (hit.object == NULL)
		return (hit);
	hit.point = dvec3_add(ray->origin, dvec3_scale(hit.t, ray->dir));
	hit.normal = calc_normal(hit.object, ray, hit.point);
	hit.color = get_object_color(hit.object);
	return (hit);
}
