/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 07:33:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "light.h"
#include "dynamic_array.h"

#include "./light_private.h"

static t_dynamic_array	g_lights = (t_dynamic_array){\
										.type_size = sizeof(t_light) \
									};

t_light const	*get_light(size_t id)
{
	return (access_dynamic_array(&g_lights, get_light_index(id)));
}

t_light	*get_mutable_light(size_t id)
{
	return (access_dynamic_array(&g_lights, get_light_index(id)));
}

size_t	get_light_count(void)
{
	return (g_lights.used);
}

bool	create_light(size_t *id)
{
	t_light	light;

	if (!add_light_id(g_lights.used, &(light.id)) \
			|| !add_dynamic_array(&g_lights, &light))
	{
		return (false);
	}
	*id = light.id;
	return (true);
}

void	cleanup_lights(void)
{
	cleanup_dynamic_array(&g_lights);
}
