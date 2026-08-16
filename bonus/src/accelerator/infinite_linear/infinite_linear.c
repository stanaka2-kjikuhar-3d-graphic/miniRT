/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_linear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:15:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:09:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "object.h"

#include "./infinite_linear_private.h"

static t_object const	**g_infinite_linear = NULL;

bool	allocate_infinite_linear(size_t infinite_count)
{
	cleanup_infinite_linear();
	if (infinite_count == 0)
		return (true);
	g_infinite_linear = malloc(sizeof(t_object *) * infinite_count);
	if (g_infinite_linear == NULL)
	{
		print_errno();
		return (false);
	}
	return (true);
}

void	register_infinite_linear(t_object const *object, size_t i)
{
	g_infinite_linear[i] = object;
}

void	cleanup_infinite_linear(void)
{
	free(g_infinite_linear);
	g_infinite_linear = NULL;
}
