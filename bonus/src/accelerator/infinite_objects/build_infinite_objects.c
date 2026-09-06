/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_infinite_objects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:17:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:13:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"

#include "./infinite_objects_private.h"

static size_t	count_infinite_objects(void);
static void		register_infinite_objects(void);

bool	build_infinite_objects(void)
{
	size_t	count;

	count = count_infinite_objects();
	if (!allocate_infinite_objects(count))
		return (false);
	if (count == 0)
		return (true);
	register_infinite_objects();
	return (true);
}

static size_t	count_infinite_objects(void)
{
	size_t			count;
	t_object const	*object;

	count = 0;
	object = NULL;
	while (get_next_object(&object))
	{
		if (!object->has_bounded_aabb)
			++count;
	}
	return (count);
}

static void	register_infinite_objects(void)
{
	t_object const	*object;
	size_t			i;

	object = NULL;
	i = 0;
	while (get_next_object(&object))
	{
		if (!object->has_bounded_aabb)
			register_infinite_object(object, i++);
	}
}
