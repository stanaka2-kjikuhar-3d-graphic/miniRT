/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 01:14:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "scene.h"

static t_light	g_light;

t_light const	*get_light(void)
{
	return (&g_light);
}

void	set_light_pos(t_dvec3 pos)
{
	g_light.pos = pos;
}

void	set_light_brightness(double brightness)
{
	g_light.brightness = brightness;
}

void	set_light_color(int color)
{
	g_light.color = color;
}
