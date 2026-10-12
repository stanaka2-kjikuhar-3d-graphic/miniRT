/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uv_layout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:15:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:27:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

#include "../../object_private.h"

void	set_uv_layout(size_t id, t_uv_layout const *layout)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->uv.layout = *layout;
}
