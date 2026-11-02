/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_window_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:21:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 21:38:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "window.h"
#include "vector.h"
#include "window_buffer.h"

#include "./window_buffer_private.h"
#include "../image_private.h"

void	put_color_window_buffer(\
	enum e_window_buffer_id id, t_ivec2 pixel, int color)
{
	*get_image_pixel_addr(get_window_buffer(id), pixel) \
		= (unsigned int)mlx_get_color_value(get_mlx_ptr(), color);
}
