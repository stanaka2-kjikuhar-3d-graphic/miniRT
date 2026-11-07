/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:04:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:08:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "ray.h"
#include "vector.h"
#include "primitive.h"

#include "../intersection_private.h"

/* Ray solved in the unit form space. See docs/primitive_intersection.md. */
float	calc_primitive_intersection(\
	t_primitive const *prim, t_ray const *ray)
{
	t_ray	local;
	float	len;

	local = transform_ray(&(prim->to_local), ray);
	if (is_planar_primitive(prim->type))
	{
		return (calc_planar_intersection(prim, &local));
	}
	else
	{
		len = vec3_length(local.dir);
		if (len < EPSILON)
			return (NAN);
		local.dir = vec3_div(len, local.dir);
		return (calc_quadric_intersection(prim, &local) / len);
	}
}
