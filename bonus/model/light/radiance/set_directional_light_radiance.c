/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directional_light_radiance.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:26:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 11:10:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "color.h"

#include "../light_private.h"

void	set_directional_light_radiance(\
	t_light_id id, t_color color, float brightness)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->directional.color = color;
	light->directional.brightness = brightness;
	light->directional.radiance = scale_color(brightness, color);
}
