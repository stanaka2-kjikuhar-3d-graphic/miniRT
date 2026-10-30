/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_directional_light.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:34:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:34:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_directional_light(t_input const *input)
{
	t_light_id						id;
	t_directional_light_input const	*directional_light;

	if (!create_light(&id))
		return (false);
	directional_light = &(input->directional_light);
	set_directional_light(id, directional_light->dir);
	set_directional_light_radiance(id, \
		directional_light->color, directional_light->brightness);
	return (true);
}
