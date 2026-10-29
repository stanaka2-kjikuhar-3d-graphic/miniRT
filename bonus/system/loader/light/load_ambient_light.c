/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:02:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_ambient_light(t_scene_input const *scene_input)
{
	t_light_id					id;
	t_ambient_light_input const	*input;

	if (!create_light(&id))
		return (false);
	input = &(scene_input->ambient_light);
	set_ambient_light(id);
	set_ambient_light_radiance(id, input->color, input->brightness);
	return (true);
}
