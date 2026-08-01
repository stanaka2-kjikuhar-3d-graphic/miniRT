/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid_quadric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:28:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 20:18:40 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"

#include "../object_private.h"

void	hyperboloid_to_quadric(\
	t_hyperboloid const *hyperboloid, t_quadric *out)
{
	t_quadric_frame	frame;
	float			radius_diff;
	float			c;

	frame.onb = hyperboloid->onb;
	frame.center = hyperboloid->center;
	radius_diff = hyperboloid->cap_radius * hyperboloid->cap_radius \
					- hyperboloid->center_radius * hyperboloid->center_radius;
	c = hyperboloid->half_height * hyperboloid->center_radius \
			/ sqrtf(radius_diff);
	frame.local_q = calc_hyperboloid_local_q(\
			hyperboloid->center_radius, hyperboloid->center_radius, c);
	frame.h_min = -hyperboloid->half_height;
	frame.h_max = hyperboloid->half_height;
	build_quadric(&frame, out);
}
