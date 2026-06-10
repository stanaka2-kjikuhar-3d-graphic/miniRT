/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 00:04:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "object.h"
#include "./object_private.h"

static t_object	*g_objects;
static size_t	g_object_count;

bool	create_object(enum e_object_type type)
{
	objects = malloc(sizeof(t_object) );
	
}

void	cleanup_objects(void)
{
	size_t	i;

	if (g_object_count == 0)
		return ;
	i = 0;
	while (i < g_object_count)
	{
		free(g_objects[i]);
		g_objects[i] = NULL;
		++i;
	}
	free(g_objects);
}

void	clear_object(size_t	id)
{
	free(g_objects[id]);
	g_objects[i] = NULL;
}
