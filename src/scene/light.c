/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 13:24:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "color.h"
#include "scene.h"

static t_light	g_light;

t_light const	*get_light(void)
{
	return (&g_light);
}

void	set_light(t_dvec3 pos, t_color color, double brightness)
{
	g_light.pos = pos;
	g_light.radiance = scale_color(brightness, color);
	g_light.color = color;
	g_light.brightness = brightness;
}
