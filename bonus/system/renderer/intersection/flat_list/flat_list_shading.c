/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_list_shading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/06 05:24:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "flat_list.h"
#include "ray.h"
#include "range.h"

#include "../intersection_private.h"

bool	flat_list_shading(t_ray const *ray, t_range range)
{
	size_t const	count = get_flat_list_count();
	size_t			i;
	float			t;

	i = 0;
	while (i < count)
	{
		t = calc_object_intersection(get_flat_list_node(i), ray);
		if (range.min < t && t < range.max)
			return (true);
		++i;
	}
	return (false);
}
