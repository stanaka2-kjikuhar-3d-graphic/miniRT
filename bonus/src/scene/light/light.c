/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 01:54:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_stdlib.h"

#include "ft_error.h"
#include "vector.h"
#include "color.h"
#include "light.h"

static t_light	*g_lights;
static size_t	g_array_size;
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

bool	add_light(t_light *light)
{
	if (g_count == g_array_size)
	{
		if (!allocate_lights(16))
		{
			g_count = 0;
			return (false);
		}
	}
	g_lights[g_count] = *light;
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
			g_array_size = 0;
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
