/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:05:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "color.h"
#include "light.h"
#include "loader.h"
#include "light_loader.h"

#include "./light_loader_private.h"

bool	create_point_light(t_scene_input const *scene_input)
{
	t_point_light_input const	*input;
	t_light						light;

	input = &(scene_input->point_light);
	light.type = POINT_LIGHT;
	light.point.color = input->color;
	light.point.brightness = input->brightness;
	light.point.radiance = scale_color(input->brightness, input->color);
	light.point.pos = input->pos;
	set_dist_attenuation(&(light.point.attenuation), LIGHT_RANGE);
	return (create_light(&light));
}
