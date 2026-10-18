/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_spot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:04:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_spot_light(t_scene_input const *scene_input)
{
	t_light_id					id;
	t_spot_light_input const	*input;

	if (!create_light(&id))
		return (false);
	input = &(scene_input->spot_light);
	set_spot_light(id, input->pos, input->dir, input->outer_angle);
	set_spot_light_radiance(id, input->color, input->brightness);
	return (true);
}
