/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buffering_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 05:57:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 06:29:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"
#include "render_mode.h"

enum e_buffering_mode	get_buffering_mode(void)
{
	t_viewport const	*viewport;

	viewport = get_viewport();
	if (get_render_mode() == RENDER_MODE_PHONG \
		|| viewport->resolution.level < RESOLUTION_COUNT
		|| viewport->sample_count == 0)
	{
		return (BUFFERING_OVERWRITE);
	}
	else
		return (BUFFERING_ACCUMULATE);
}
