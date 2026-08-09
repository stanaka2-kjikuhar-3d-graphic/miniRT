/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_aabb_from_extent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:30:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/09 14:41:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_aabb	calc_aabb_from_extent(t_vec3 center, t_vec3 extent)
{
	return ((t_aabb){\
		.x = (t_range){.min = center.x - extent.x, \
						.max = center.x + extent.x}, \
		.y = (t_range){.min = center.y - extent.y, \
						.max = center.y + extent.y}, \
		.z = (t_range){.min = center.z - extent.z, \
						.max = center.z + extent.z} \
	});
}
