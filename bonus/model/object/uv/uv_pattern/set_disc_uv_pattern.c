/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_uv_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:09:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:18:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "id.h"

#include "./uv_pattern_private.h"

void	set_disc_uv_pattern(t_object_id id, float pattern_size)
{
	t_uv_pattern	pattern;

	pattern.size = pattern_size;
	set_uv_pattern(id, &pattern);
}
