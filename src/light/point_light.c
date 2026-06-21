/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:38:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	add_point_light(t_input_point_light const *input)
{
	t_light	light;

	light.type = POINT_LIGHT;
	light.pos = input->pos;
	light.color = input->color;
	light.brightness = input->brightness;
	light.radiance = scale_color(input->brightness, input->color);
	return (add_light(&light));
}
