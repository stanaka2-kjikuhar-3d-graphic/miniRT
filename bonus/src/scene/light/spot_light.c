/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 20:38:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "color.h"
#include "light.h"

#include "ft_math.h"

#include "./light_private.h"

bool	create_spot_light(t_input_spot_light const *input)
{
	t_light	light;

	light.type = SPOT_LIGHT;
	light.spot.color = input->color;
	light.spot.brightness = input->brightness;
	light.spot.radiance = scale_color(input->brightness, input->color);
	light.spot.pos = input->pos;
	light.spot.dir = input->dir;
	light.spot.angle.outer = input->outer_angle;
	light.spot.angle.cos_half_outer \
		= cosf((float)(light.spot.angle.outer / 2.0 * DEG_TO_RAD));
	light.spot.angle.inner = 0.5f * input->outer_angle;
	light.spot.angle.cos_half_inner \
		= cosf((float)(light.spot.angle.inner / 2.0 * DEG_TO_RAD));
	set_dist_attenuation(&(light.spot.attenuation), LIGHT_RANGE);
	return (create_light(&light));
}

float	calc_spot_light_attenuation(\
	t_spot_light const *light, float dist, float dot)
{
	float	attenuation;
	float	angle_ratio;

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
