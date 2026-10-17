/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_uniform_infinite_light.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:27:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:12:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "loader_light.h"
#include "id.h"

bool	load_uniform_infinite_light(t_scene_input const *scene_input)
{
	t_id									light_id;
	t_uniform_infinite_light_input const	*input;

	if (!create_light(&light_id))
		return (false);
	input = &(scene_input->uniform_infinite_light);
	set_uniform_infinite_light(light_id);
	set_uniform_infinite_light_radiance(light_id, input->color, input->brightness);
	return (true);
}
