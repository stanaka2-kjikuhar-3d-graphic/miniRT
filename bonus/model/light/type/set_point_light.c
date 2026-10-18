/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:08:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:19:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "vector.h"
#include "id.h"

#include "../light_private.h"

void	set_point_light(t_light_id id, t_vec3 pos)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->type = POINT_LIGHT;
	light->point.pos = pos;
}
