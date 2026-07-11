/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 05:56:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	create_ambient_light(t_input_ambient_light const *input)
{
	t_light	light;

	light.type = AMBIENT_LIGHT;
	light.ambient.color = input->color;
	light.ambient.brightness = input->brightness;
	light.ambient.radiance = scale_color(input->brightness, input->color);
	return (create_light(&light));
}
