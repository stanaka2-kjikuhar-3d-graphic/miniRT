/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_spot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 14:30:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_math.h"

#include "config.h"
#include "color.h"
#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_spot_light(t_scene_input const *scene_input)
{
	size_t						id;
	t_spot_light_input const	*input;

	if (!create_light(&id))
		return (false);
	input = &(scene_input->spot_light);
	set_spot_light(id, input->pos, input->dir, input->outer_angle);
	set_spot_light_radiance(id, input->color, input->brightness);
	return (true);
}
