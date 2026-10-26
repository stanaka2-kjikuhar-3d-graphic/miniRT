/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_hit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:52:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "ray.h"

#include "./intersection_private.h"
#include "../renderer_private.h"

t_hit	find_closest_hit(t_ray const *ray)
{
	t_hit	hit;

	hit = (t_hit){.object = NULL, .t = INFINITY};
	flat_list_intersection(&hit, ray);
	bvh_intersection(&hit, ray);
	return (hit);
}
