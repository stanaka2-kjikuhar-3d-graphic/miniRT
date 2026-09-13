/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_directional_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:34:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:08:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "light_loader.h"

bool	create_directional_light(t_scene_input const *scene_input)
{
	t_directional_light_input const	*input;
	t_light							light;

	input = &(scene_input->directional_light);
	light.type = DIRECTIONAL_LIGHT;
	light.directional.color = input->color;
	light.directional.brightness = input->brightness;
	light.directional.radiance = scale_color(input->brightness, input->color);
	light.directional.dir = input->dir;
	return (create_light(&light));
}
