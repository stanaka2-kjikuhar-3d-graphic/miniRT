/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_quadric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:55:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 20:16:56 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static t_mat3	frame_basis(t_onb const *onb);

void	build_quadric(t_quadric_frame const *frame, t_quadric *out)
{
	t_mat4	local_to_world;
	t_mat3	basis;

	basis = frame_basis(&frame->onb);
	local_to_world = mat4_basis(&basis, frame->center);
	out->q = quadric_to_world(&(frame->local_q), &local_to_world);
	out->finite = true;
	out->axis = frame->onb.w;
	out->center = frame->center;
	out->h_min = frame->h_min;
	out->h_max = frame->h_max;
}

static t_mat3	frame_basis(t_onb const *onb)
{
	t_mat3	basis;

	basis.m[0][0] = onb->u.x;
	basis.m[1][0] = onb->u.y;
	basis.m[2][0] = onb->u.z;
	basis.m[0][1] = onb->v.x;
	basis.m[1][1] = onb->v.y;
	basis.m[2][1] = onb->v.z;
	basis.m[0][2] = onb->w.x;
	basis.m[1][2] = onb->w.y;
	basis.m[2][2] = onb->w.z;
	return (basis);
}
