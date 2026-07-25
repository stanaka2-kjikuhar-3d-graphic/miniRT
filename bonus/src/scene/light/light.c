/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 01:01:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "vector.h"
#include "color.h"
#include "light.h"
#include "dynamic_array.h"

static t_light	*g_lights;
static size_t	g_capacity;
static size_t	g_count;

bool	get_next_light(t_light const **light)
{
	if (*light == NULL)
	{
		if (g_count == 0)
			return (false);
		*light = &(g_lights[0]);
		return (true);
	}
	else
	{
		if (*light == &(g_lights[g_count - 1]))
			return (false);
		++(*light);
		return (true);
	}
}

bool	create_light(t_light *light)
{
	if (g_count == g_capacity && !grow_dynamic_array(\
						(void **)(&g_lights), &g_capacity, sizeof(t_light)))
	{
		return (false);
	}
	g_lights[g_count] = *light;
	++g_count;
	return (true);
}

void	cleanup_lights(void)
{
	if (g_lights == NULL)
		return ;
	free(g_lights);
	g_lights = NULL;
	g_capacity = 0;
	g_count = 0;
}
