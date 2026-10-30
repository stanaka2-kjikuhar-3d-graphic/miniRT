/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_point_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:36:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:35:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_point_light(t_input const *input)
{
	t_light_id					id;
	t_point_light_input const	*point_light;

	if (!create_light(&id))
		return (false);
	point_light = &(input->point_light);
	set_point_light(id, point_light->pos);
	set_point_light_radiance(id, point_light->color, point_light->brightness);
	return (true);
}
