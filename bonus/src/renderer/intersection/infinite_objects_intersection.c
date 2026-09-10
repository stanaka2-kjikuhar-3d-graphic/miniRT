/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_objects_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:29:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/10 21:25:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "object.h"
#include "accelerator.h"

#include "intersection_private.h"

void	infinite_objects_intersection(t_hit *hit, t_ray const *ray)
{
	size_t const	count = get_infinite_object_count();
	size_t			i;
	float			t;
	t_object const	*object;

	i = 0;
	while (i < count)
	{
		object = get_infinite_object(i);
		t = calc_object_intersection(object, ray);
		if (EPSILON < t && t < hit->t)
		{
			hit->object = object;
			hit->t = t;
		}
		++i;
	}
}
