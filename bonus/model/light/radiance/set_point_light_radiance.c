/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_light_radiance.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:26:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:54:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "light.h"
#include "color.h"
#include "id.h"

#include "../light_private.h"
#include "./light_radiance_private.h"

void	set_point_light_radiance(t_id id, t_color color, float brightness)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->point.color = color;
	light->point.brightness = brightness;
	light->point.radiance = scale_color(brightness, color);
	set_dist_attenuation(&(light->point.attenuation), LIGHT_RANGE);
}
