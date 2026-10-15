/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_uv_layout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:08:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:26:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "range.h"

#include "./uv_layout_private.h"

void	set_disc_uv_layout(size_t id, t_uv_layout const *layout)
{
	set_uv_layout(id, layout);
}
