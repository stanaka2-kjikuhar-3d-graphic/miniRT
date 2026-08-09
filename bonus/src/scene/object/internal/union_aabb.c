/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_aabb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:30:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/09 14:30:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "vector.h"

t_aabb	union_aabb(t_aabb a, t_aabb b)
{
	return ((t_aabb){\
		.x = (t_range){.min = fminf(a.x.min, b.x.min), \
						.max = fmaxf(a.x.max, b.x.max)}, \
		.y = (t_range){.min = fminf(a.y.min, b.y.min), \
						.max = fmaxf(a.y.max, b.y.max)}, \
		.z = (t_range){.min = fminf(a.z.min, b.z.min), \
						.max = fmaxf(a.z.max, b.z.max)} \
	});
}
