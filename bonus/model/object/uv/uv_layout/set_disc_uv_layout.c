/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_uv_layout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:08:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:15:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "range.h"
#include "id.h"

#include "./uv_layout_private.h"

void	set_disc_uv_layout(t_id object_id, t_uv_layout const *layout)
{
	set_uv_layout(object_id, layout);
}
