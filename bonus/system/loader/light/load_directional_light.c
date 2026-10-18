/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_directional_light.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:34:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:27:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "loader_light.h"
#include "id.h"

bool	load_directional_light(t_scene_input const *scene_input)
{
	t_light_id						id;
	t_directional_light_input const	*input;

	if (!create_light(&id))
		return (false);
	input = &(scene_input->directional_light);
	set_directional_light(id, input->dir);
	set_directional_light_radiance(id, input->color, input->brightness);
	return (true);
}
