/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:39:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 13:28:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "scene.h"
#include "color.h"

static t_ambient_lighting	g_ambient_lighting;

t_ambient_lighting const	*get_ambient_lighting(void)
{
	return (&g_ambient_lighting);
}

void	set_ambient_lighting(t_color color, double brightness)
{
	g_ambient_lighting.radiance = scale_color(brightness, color);
	g_ambient_lighting.color = color;
	g_ambient_lighting.brightness = brightness;
}
