/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid_quadric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:58:56 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 20:19:06 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

void	paraboloid_to_quadric(\
	t_paraboloid const *paraboloid, t_quadric *out)
{
	t_quadric_frame	frame;

	frame.onb = paraboloid->onb;
	frame.center = paraboloid->center;
	frame.local_q = calc_paraboloid_local_q(paraboloid->quadratic_coefficient);
	frame.h_min = 0.0f;
	frame.h_max = paraboloid->height;
	build_quadric(&frame, out);
}
