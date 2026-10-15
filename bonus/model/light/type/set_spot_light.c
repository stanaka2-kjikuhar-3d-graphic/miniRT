/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spot_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:08:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 13:50:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "ft_math.h"

#include "light.h"
#include "vector.h"

#include "../light_private.h"

void	set_spot_light(size_t id, t_vec3 pos, t_vec3 dir, float outer_angle)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->type = SPOT_LIGHT;
	light->spot.pos = pos;
	light->spot.dir = dir;
	light->spot.angle.outer = outer_angle;
	light->spot.angle.cos_half_outer \
		= cosf((float)(light->spot.angle.outer / 2.0 * DEG_TO_RAD));
	light->spot.angle.inner = 0.5f * outer_angle;
	light->spot.angle.cos_half_inner \
		= cosf((float)(light->spot.angle.inner / 2.0 * DEG_TO_RAD));
}
