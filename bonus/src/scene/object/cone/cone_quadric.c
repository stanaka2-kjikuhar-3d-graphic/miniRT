/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_quadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 18:34:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 18:38:21 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static t_mat3	cone_basis(t_cone const *cone);

void	cone_to_quadric(t_cone const *cone, t_quadric *out)
{
	t_mat4	local_to_world;
	t_vec3	apex;
	float	k;

	apex = vec3_add(cone->center, vec3_scale(cone->height, cone->dir));
	local_to_world = mat4_basis(cone_basis(cone), apex);
	k = cone->radius / cone->height;
	out->q = quadric_to_world(cone_local_q(k), local_to_world);
	out->finite = true;
	out->axis = vec3_scale(-1.0f, cone->dir);
	out->center = apex;
	out->h_min = 0.0f;
	out->h_max = cone->height;
}

static t_mat3	cone_basis(t_cone const *cone)
{
	t_mat3	basis;
	t_vec3	w_axis;

	w_axis = vec3_scale(-1.0f, cone->dir);
	basis.m[0][0] = cone->onb.u.x;
	basis.m[1][0] = cone->onb.u.y;
	basis.m[2][0] = cone->onb.u.z;
	basis.m[0][1] = cone->onb.v.x;
	basis.m[1][1] = cone->onb.v.y;
	basis.m[2][1] = cone->onb.v.z;
	basis.m[0][2] = w_axis.x;
	basis.m[1][2] = w_axis.y;
	basis.m[2][2] = w_axis.z;
	return (basis);
}
