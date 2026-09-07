/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:38:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:24:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"
#include "ft_mlx.h"
#include "renderer.h"
#include "viewport.h"
#include "vector.h"

#include "./renderer_private.h"

static void	rendering(void);

void	renderer(void)
{
	if (check_render_flag())
	{
		rendering();
		mlx_put_image_to_window(\
			get_mlx_ptr(), get_win_ptr(), get_image(IMG_WINDOW)->ptr, 0, 0);
		set_render_flag(false);
	}
}

static void	rendering(void)
{
	t_viewport const	*viewport;
	int					pixel_num;
	t_ivec2				pixel;

	viewport = get_viewport();
	pixel_num = 0;
	while (pixel_num < viewport->pixel_count)
	{
		pixel.y = pixel_num / viewport->pixel_size.x;
		pixel.x = pixel_num % viewport->pixel_size.x;
		phong(pixel);
		++pixel_num;
	}
}
