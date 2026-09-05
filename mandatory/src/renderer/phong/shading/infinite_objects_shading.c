/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_objects_shading.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 22:18:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "config.h"
#include "object.h"
#include "accelerator.h"

#include "../phong_private.h"

bool	infinite_objects_shading(t_ray const *ray, float dist)
{
	size_t const	count = get_infinite_object_count();
	size_t			i;
	float			t;

	i = 0;
	while (i < count)
	{
		t = calc_object_intersection(get_infinite_object(i), ray);
		if (0.0f < t && t < dist)
			return (true);
		++i;
	}
	return (false);
}
