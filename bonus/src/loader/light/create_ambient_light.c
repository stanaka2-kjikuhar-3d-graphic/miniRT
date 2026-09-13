/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:12:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "light_loader.h"

bool	create_ambient_light(t_scene_input const *scene_input)
{
	t_ambient_light_input const	*input;
	t_light						light;

	input = &(scene_input->ambient_light);
	light.type = AMBIENT_LIGHT;
	light.ambient.color = input->color;
	light.ambient.brightness = input->brightness;
	light.ambient.radiance = scale_color(input->brightness, input->color);
	return (create_light(&light));
}
