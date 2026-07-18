/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/14 13:46:11 by stanaka2         ###   ########.fr       */
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
static size_t	g_capacity;
static size_t	g_count;

static bool	allocate_lights(void);

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
	if (g_count == g_capacity && !allocate_lights())
		return (false);
	g_lights[g_count] = *light;
	++g_count;
	return (true);
}

static bool	allocate_lights(void)
{
	t_light	*tmp;

	if (g_lights == NULL)
		tmp = malloc(sizeof(t_light));
	else
	{
		tmp = ft_realloc(g_lights, \
				sizeof(t_light) * g_capacity, \
				sizeof(t_light) * (g_capacity * 2));
	}
	if (tmp == NULL)
	{
		print_errno();
		return (false);
	}
	g_lights = tmp;
	if (g_capacity == 0)
		g_capacity = 1;
	else
		g_capacity *= 2;
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
