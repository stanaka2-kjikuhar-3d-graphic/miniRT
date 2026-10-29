/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_uniform_infinite_light.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:27:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:21:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_uniform_infinite_light(t_scene_input const *scene_input)
{
	t_light_id								id;
	t_uniform_infinite_light_input const	*input;

	if (!create_light(&id))
		return (false);
	input = &(scene_input->uniform_infinite_light);
	set_uniform_infinite_light(id);
	set_uniform_infinite_light_radiance(id, input->color, input->brightness);
	return (true);
}
