/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform_infinite_light.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:27:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 17:03:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"

#include "./light_private.h"

bool	create_uniform_infinite_light(\
	t_input_uniform_infinite_light const *input)
{
	t_light	light;

	light.type = UNIFORM_INFINITE_LIGHT;
	light.uniform_infinite.color = input->color;
	light.uniform_infinite.brightness = input->brightness;
	light.uniform_infinite.radiance \
		= scale_color(input->brightness, input->color);
	return (create_light(&light));
}
