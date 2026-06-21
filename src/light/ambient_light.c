/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 14:47:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "light.h"
#include "color.h"

static t_ambient_light	g_ambient_light;

t_ambient_light const	*get_ambient_light(void)
{
	return (&g_ambient_light);
}

void	set_ambient_light(t_input_ambient const *input)
{
	g_ambient_light.color = input->color;
	g_ambient_light.brightness = input->brightness;
	g_ambient_light.radiance = scale_color(input->brightness, input->color);
}
