/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_infinite_objects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:17:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/05 07:00:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "aabb.h"

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
	size_t			infinite_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	infinite_count = 0;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object(i);
		if (!(object->aabb_info.has_bounded_aabb))
			++infinite_count;
		++i;
	}
	return (infinite_count);
}

static void	register_infinite_objects(void)
{
	size_t			infinite_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	infinite_count = 0;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object(i);
		if (!(object->aabb_info.has_bounded_aabb))
			register_infinite_object(object, infinite_count++);
		++i;
	}
}
