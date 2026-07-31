/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid_quadric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:28:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 21:28:38 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static t_mat3	hyperboloid_basis(t_hyperboloid const *hyperboloid);

void	hyperboloid_to_quadric(\
	t_hyperboloid const *hyperboloid, t_quadric *out)
{
	t_mat4	local_to_world;
	float	c;
	float	radius_diff;

	local_to_world = mat4_basis(\
			hyperboloid_basis(hyperboloid), hyperboloid->center);
	radius_diff = hyperboloid->cap_radius * hyperboloid->cap_radius \
					- hyperboloid->center_radius * hyperboloid->center_radius;
	c = hyperboloid->half_height * hyperboloid->center_radius \
			/ sqrtf(radius_diff);
	out->q = quadric_to_world(hyperboloid_local_q(\
				hyperboloid->center_radius, hyperboloid->center_radius, c), \
			local_to_world);
	out->finite = true;
	out->axis = hyperboloid->dir;
	out->center = hyperboloid->center;
	out->h_min = -hyperboloid->half_height;
	out->h_max = hyperboloid->half_height;
}

static t_mat3	hyperboloid_basis(t_hyperboloid const *hyperboloid)
{
	t_mat3	basis;

	basis.m[0][0] = hyperboloid->onb.u.x;
	basis.m[1][0] = hyperboloid->onb.u.y;
	basis.m[2][0] = hyperboloid->onb.u.z;
	basis.m[0][1] = hyperboloid->onb.v.x;
	basis.m[1][1] = hyperboloid->onb.v.y;
	basis.m[2][1] = hyperboloid->onb.v.z;
	basis.m[0][2] = hyperboloid->dir.x;
	basis.m[1][2] = hyperboloid->dir.y;
	basis.m[2][2] = hyperboloid->dir.z;
	return (basis);
}
