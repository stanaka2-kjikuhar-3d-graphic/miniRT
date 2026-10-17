/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform_infinite_light_radiance.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:26:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:05:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "color.h"
#include "id.h"

#include "../light_private.h"

void	set_uniform_infinite_light_radiance(\
	t_id light_id, t_color color, float brightness)
{
	t_light	*light;

	light = get_mutable_light(light_id);
	light->uniform_infinite.color = color;
	light->uniform_infinite.brightness = brightness;
	light->uniform_infinite.radiance = scale_color(brightness, color);
}
