/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uv_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:09:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:28:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

#include "../../object_private.h"

void	set_uv_pattern(size_t id, t_uv_pattern const *pattern)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->uv.pattern = *pattern;
}
