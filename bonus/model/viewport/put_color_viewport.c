/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_viewport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:01:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 06:11:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "viewport.h"
#include "vector.h"
#include "config.h"

#include "./viewport_private.h"

void	put_color_viewport(\
	enum e_buffering_mode mode, t_ivec2 pixel, t_color color)
{
	t_viewport	*viewport;
	size_t		i;

	viewport = get_mutable_viewport();
	i = (size_t)pixel.y * WINDOW_WIDTH + pixel.x;
	if (mode == BUFFERING_OVERWRITE)
		viewport->buffer[i] = color;
	else if (mode == BUFFERING_ACCUMULATE)
		viewport->buffer[i] = add_color(viewport->buffer[i], color);
}
