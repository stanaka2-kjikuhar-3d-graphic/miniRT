/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 20:34:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	create_point_light(t_input_point_light const *input)
{
	t_light	light;

	light.type = POINT_LIGHT;
	light.point.color = input->color;
	light.point.brightness = input->brightness;
	light.point.radiance = scale_color(input->brightness, input->color);
	light.point.pos = input->pos;
	set_dist_attenuation(&(light.point.attenuation), LIGHT_RANGE);
	return (create_light(&light));
}

float	calc_point_light_attenuation(t_point_light const *light, float dist)
{
	return (calc_dist_attenuation(&(light->attenuation), dist));
}
