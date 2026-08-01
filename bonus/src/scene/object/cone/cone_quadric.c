/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_quadric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 18:34:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 19:57:59 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"

#include "../object_private.h"

void	cone_to_quadric(t_cone const *cone, t_quadric *out)
{
	t_quadric_frame	frame;

	frame.onb.u = cone->onb.u;
	frame.onb.v = cone->onb.v;
	frame.onb.w = vec3_scale(-1.0f, cone->dir);
	frame.center = vec3_add(cone->center, vec3_scale(cone->height, cone->dir));
	frame.local_q = cone_local_q(cone->radius / cone->height);
	frame.h_min = 0.0f;
	frame.h_max = cone->height;
	quadric_build(&frame, out);
}
