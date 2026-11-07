/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 06:31:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/02 07:06:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

#include "./viewport_private.h"

void	set_resolution_level(enum e_resolution_level level)
{
	get_mutable_viewport()->resolution.level = level;
}

void	increment_resolution_level(void)
{
	t_viewport	*viewport;

	viewport = get_mutable_viewport();
	if (viewport->resolution.level < RESOLUTION_COUNT)
		++viewport->resolution.level;
}
