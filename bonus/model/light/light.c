/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:36:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "dynamic_array.h"

#include "./light_private.h"

static t_dynamic_array	g_lights = (t_dynamic_array){\
										.type_size = sizeof(t_light) \
									};

t_dynamic_array	*get_mutable_light_array(void)
{
	return (&g_lights);
}

t_light const	*get_light(t_light_id id)
{
	return (access_dynamic_array(&g_lights, get_light_index(id)));
}

t_light const	*get_light_by_index(size_t i)
{
	return (access_dynamic_array(&g_lights, i));
}

t_light	*get_mutable_light(t_light_id id)
{
	return (access_dynamic_array(&g_lights, get_light_index(id)));
}
