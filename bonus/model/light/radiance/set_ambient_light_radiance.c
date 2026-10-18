/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light_radiance.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:24:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:54:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "color.h"
#include "id.h"

#include "../light_private.h"

void	set_ambient_light_radiance(t_id id, t_color color, float brightness)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->ambient.color = color;
	light->ambient.brightness = brightness;
	light->ambient.radiance = scale_color(brightness, color);
}
