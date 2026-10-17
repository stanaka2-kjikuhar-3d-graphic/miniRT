/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_point_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:12:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "color.h"
#include "light.h"
#include "loader.h"
#include "loader_light.h"
#include "id.h"

bool	load_point_light(t_scene_input const *scene_input)
{
	t_id						light_id;
	t_point_light_input const	*input;

	if (!create_light(&light_id))
		return (false);
	input = &(scene_input->point_light);
	set_point_light(light_id, input->pos);
	set_point_light_radiance(light_id, input->color, input->brightness);
	return (true);
}
