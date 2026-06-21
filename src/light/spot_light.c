/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:38:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	add_spot_light(t_input_spot_light const *input)
{
	t_light	light;

	light.type = SPOT_LIGHT;
	light.pos = input->pos;
	light.color = input->color;
	light.brightness = input->brightness;
	light.spot.dir = input->dir;
	light.spot.angle = input->angle;
	light.radiance = scale_color(input->brightness, input->color);
	return (add_light(&light));
}
