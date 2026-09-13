/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_uniform_infinite_light.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:27:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:05:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "light_loader.h"

bool	create_uniform_infinite_light(t_scene_input const *scene_input)
{
	t_uniform_infinite_light_input const	*input;
	t_light									light;

	input = &(scene_input->uniform_infinite_light);
	light.type = UNIFORM_INFINITE_LIGHT;
	light.uniform_infinite.color = input->color;
	light.uniform_infinite.brightness = input->brightness;
	light.uniform_infinite.radiance \
		= scale_color(input->brightness, input->color);
	return (create_light(&light));
}
