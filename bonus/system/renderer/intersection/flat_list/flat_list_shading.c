/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_list_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:52:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "flat_list.h"
#include "ray.h"

#include "../intersection_private.h"

bool	flat_list_shading(t_ray const *ray, float dist)
{
	size_t const	count = get_flat_list_count();
	size_t			i;
	float			t;

	i = 0;
	while (i < count)
	{
		t = calc_object_intersection(get_flat_list_node(i), ray);
		if (0.0f < t && t < dist)
			return (true);
		++i;
	}
	return (false);
}
