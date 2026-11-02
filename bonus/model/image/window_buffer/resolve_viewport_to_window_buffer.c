/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_viewport_to_window_buffer.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 22:02:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 07:08:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "window_buffer.h"
#include "viewport.h"
#include "vector.h"
#include "window.h"

#include "./window_buffer_private.h"
#include "../image_private.h"

void	resolve_viewport_to_window_buffer(enum e_window_buffer_id id)
{
	t_image			*image;
	t_ivec2			pixel;
	t_vec2			uv;
	unsigned int	color;

	image = get_window_buffer(id);
	pixel.y = 0;
	while (pixel.y < image->height)
	{
		pixel.x = 0;
		while (pixel.x < image->width)
		{
			uv = (t_vec2){\
				.width = ((float)pixel.x + 0.5f) / (float)(image->width), \
				.height = ((float)pixel.y + 0.5f) / (float)(image->height) \
			};
			color = (unsigned int)mlx_get_color_value(get_mlx_ptr(), \
						encode_color(resolve_viewport_color(uv)));
			*get_image_pixel_addr(image, pixel) = color;
			++(pixel.x);
		}
		++(pixel.y);
	}
}
