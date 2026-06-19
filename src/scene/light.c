/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 18:59:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_error.h"
#include "vector.h"
#include "color.h"
#include "scene.h"

static t_light	*g_lights;
static size_t	g_array_size;
static size_t	g_count;

bool	get_next_light(t_light const	**light)
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

bool	add_light(t_dvec3 pos, t_color color, double brightness)
{
	if (g_count == g_array_size)
	{
		if (!allocate_lights(4))
			return (false);
	}
	g_lights[g_count].pos = pos;
	g_lights[g_count].radiance = scale_color(brightness, color);
	g_lights[g_count].color = color;
	g_lights[g_count].brightness = brightness;
	++g_count;
	return (true);
}

bool	allocate_lights(size_t add_count)
{
	if (g_lights == NULL)
	{
		g_lights = malloc(sizeof(t_light) * add_count);
		if (g_lights == NULL)
		{
			print_errno();
			return (false);
		}
		g_array_size = add_count;
	}
	else
	{
		g_lights = ft_reallocf(g_lights, \
						sizeof(t_light) * g_array_size, \
						sizeof(t_light) * (g_array_size + add_count));
		if (g_lights == NULL)
		{
			print_errno();
			return (false);
		}
		g_array_size += add_count;
	}
	return (true);
}

void	cleanup_lights(void)
{
	if (g_lights == NULL)
		return ;
	free(g_lights);
	g_lights = NULL;
	g_array_size = 0;
	g_count = 0;
}
