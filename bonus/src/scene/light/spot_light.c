/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 05:56:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "ft_math.h"

#include "./light_private.h"

bool	create_spot_light(t_input_spot_light const *input)
{
	t_light	light;

	light.type = SPOT_LIGHT;
	light.spot.color = input->color;
	light.spot.brightness = input->brightness;
	light.spot.radiance = scale_color(input->brightness, input->color);
	light.spot.pos = input->pos;
	light.spot.dir = input->dir;
	light.spot.angle.outer = input->outer_angle;
	light.spot.angle.inner = 0.8f * input->outer_angle;
	return (create_light(&light));
}
