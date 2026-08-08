/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_planar_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:12:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/07 22:27:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

/*
UNIT_PLANE is z = 0 and UNIT_DISC adds x^2 + y^2 <= 1, so neither one is
a quadric: unit_quadric hands back a form that has no root, and both are
solved here instead.

  the local ray already carries the world t, so t is returned as it is.
*/
float	calc_planar_intersection(t_primitive const *prim, t_ray const *local)
{
	float	t;
	float	x;
	float	y;

	if (fabsf(local->dir.z) < EPSILON)
		return (NAN);
	t = -local->origin.z / local->dir.z;
	if (t < 0.0f)
		return (NAN);
	if (prim->type == UNIT_DISC)
	{
		x = local->origin.x + t * local->dir.x;
		y = local->origin.y + t * local->dir.y;
		if (x * x + y * y > 1.0f)
			return (NAN);
	}
	return (t);
}
