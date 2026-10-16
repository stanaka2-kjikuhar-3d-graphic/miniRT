/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:12:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "color.h"
#include "light.h"
#include "loader.h"
#include "loader_light.h"
#include "id.h"

bool	load_ambient_light(t_scene_input const *scene_input)
{
	t_id						light_id;
	t_ambient_light_input const	*input;

	if (!create_light(&light_id))
		return (false);
	input = &(scene_input->ambient_light);
	set_ambient_light(light_id);
	set_ambient_light_radiance(light_id, input->color, input->brightness);
	return (true);
}
