/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_spot_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:49:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_spot_light(t_input const *input)
{
	t_light_id					id;
	t_spot_light_input const	*spot_light;

	if (!create_light(&id))
		return (false);
	spot_light = &(input->spot_light);
	set_spot_light(id, \
		spot_light->pos, spot_light->dir, spot_light->outer_angle);
	set_spot_light_radiance(id, spot_light->color, spot_light->brightness);
	return (true);
}
