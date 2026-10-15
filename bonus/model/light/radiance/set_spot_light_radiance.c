/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spot_light_radiance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:26:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 14:56:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "light.h"
#include "color.h"

#include "../light_private.h"
#include "./light_radiance_private.h"

void	set_spot_light_radiance(size_t id, t_color color, float brightness)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->spot.color = color;
	light->spot.brightness = brightness;
	light->spot.radiance = scale_color(brightness, color);
	set_dist_attenuation(&(light->spot.attenuation), LIGHT_RANGE);
}
