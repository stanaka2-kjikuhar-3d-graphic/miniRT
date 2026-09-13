/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:04:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/13 14:29:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

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
