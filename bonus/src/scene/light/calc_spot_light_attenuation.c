/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_spot_light_attenuation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:25:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 17:41:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "light.h"
#include "config.h"

#include "./light_private.h"

float	calc_spot_light_attenuation(\
	t_spot_light const *light, float dist, float dot)
{
	float	attenuation;
	float	angle_ratio;

	if (dot <= light->angle.cos_half_outer)
		return (0.0f);
	attenuation = calc_dist_attenuation(&(light->attenuation), dist);
	if (dot > light->angle.cos_half_inner)
		angle_ratio = 1.0f;
	else
	{
		angle_ratio = ((dot - light->angle.cos_half_outer) \
				/ (light->angle.cos_half_inner - light->angle.cos_half_outer));
	}
	if (SPOT_LIGHT_FALLOFF == 1.0)
		attenuation *= angle_ratio;
	else
		attenuation *= powf(angle_ratio, (float)SPOT_LIGHT_FALLOFF);
	return (attenuation);
}
