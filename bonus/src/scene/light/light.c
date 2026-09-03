/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:41:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "vector.h"
#include "color.h"
#include "light.h"
#include "dynamic_array.h"

static t_dynamic_array	g_lights = (t_dynamic_array){\
										.data = NULL, \
										.capacity = 0, \
										.used = 0, \
										.type_size = sizeof(t_light) \
									};

bool	get_next_light(t_light const **light)
{
	t_light const	*last;

	if (g_lights.used == 0)
		return (false);
	last = access_dynamic_array(&g_lights, g_lights.used - 1);
	if (*light == last)
		return (false);
	if (*light == NULL)
		*light = (t_light const *)(g_lights.data);
	else
		++(*light);
	return (true);
}

bool	create_light(t_light const *light)
{
	return (add_dynamic_array(&g_lights, light));
}

void	cleanup_lights(void)
{
	cleanup_dynamic_array(&g_lights);
}
