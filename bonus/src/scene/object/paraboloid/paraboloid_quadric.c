/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_quadric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:58:56 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 20:58:56 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static t_mat3	paraboloid_basis(t_paraboloid const *paraboloid);

void	paraboloid_to_quadric(\
	t_paraboloid const *paraboloid, t_quadric *out)
{
	t_mat4	local_to_world;

	local_to_world = mat4_basis(\
			paraboloid_basis(paraboloid), paraboloid->center);
	out->q = quadric_to_world(\
			paraboloid_local_q(paraboloid->quadratic_coefficient), \
			local_to_world);
	out->finite = true;
	out->axis = paraboloid->dir;
	out->center = paraboloid->center;
	out->h_min = 0.0f;
	out->h_max = paraboloid->height;
}

static t_mat3	paraboloid_basis(t_paraboloid const *paraboloid)
{
	t_mat3	basis;

	basis.m[0][0] = paraboloid->onb.u.x;
	basis.m[1][0] = paraboloid->onb.u.y;
	basis.m[2][0] = paraboloid->onb.u.z;
	basis.m[0][1] = paraboloid->onb.v.x;
	basis.m[1][1] = paraboloid->onb.v.y;
	basis.m[2][1] = paraboloid->onb.v.z;
	basis.m[0][2] = paraboloid->dir.x;
	basis.m[1][2] = paraboloid->dir.y;
	basis.m[2][2] = paraboloid->dir.z;
	return (basis);
}
