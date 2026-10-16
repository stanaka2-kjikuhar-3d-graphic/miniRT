/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:29:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 05:37:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "object.h"
#include "flat_list.h"

#include "../intersection_private.h"

void	flat_list_intersection(t_hit *hit, t_ray const *ray)
{
	size_t const	count = get_flat_list_count();
	size_t			i;
	float			t;
	t_object const	*object;

	i = 0;
	while (i < count)
	{
		object = get_flat_list_node(i);
		t = calc_object_intersection(object, ray);
		if (EPSILON < t && t < hit->t)
		{
			hit->object = object;
			hit->t = t;
		}
		++i;
	}
}
