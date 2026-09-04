/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directional_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:34:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 17:03:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	create_directional_light(t_input_directional_light const *input)
{
	t_light	light;

	light.type = DIRECTIONAL_LIGHT;
	light.directional.color = input->color;
	light.directional.brightness = input->brightness;
	light.directional.radiance = scale_color(input->brightness, input->color);
	light.directional.dir = input->dir;
	return (create_light(&light));
}
