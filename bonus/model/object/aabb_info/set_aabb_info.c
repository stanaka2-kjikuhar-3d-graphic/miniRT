/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_aabb_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:32:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 07:16:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "aabb.h"

#include "../object_private.h"

void	set_aabb_info(size_t id, t_aabb_info const *aabb_info)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->aabb_info = *aabb_info;
}
