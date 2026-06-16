/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 23:52:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "ray.h"
#include "./phong_reflection_model_private.h"

static double	intersect(t_object const *object, t_ray const *ray);

t_hit	intersects(t_ray const *ray)
{
	t_object const	*const	objects = get_objects();
	size_t const			count = get_objects_count();
	t_hit					hit;
	size_t					i;
	double					tmp;
	
	hit.object = NULL;
	hit.t = INFINITY;
	i = 0;
	while (i < count)
	{
		tmp = intersect(&(objects[i]), ray);
		if (hit.t > tmp)
		{
			hit.object = &(objects[i]);
			hit.t = tmp;
		}
		++i;
	}
	return (hit);
}

static double	intersect(t_object const *object, t_ray const *ray)
{
	if (object->type == OBJ_SPHERE)
		return (intersect_sphere(&(object->sphere), ray));
	return (NAN);
}
