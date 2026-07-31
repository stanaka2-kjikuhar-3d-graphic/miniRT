/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:21:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/28 23:27:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "ft_mlx.h"
#include "vector.h"

void	put_color(t_image *image, t_ivec2 pixel, int color)
{
	*get_pixel_addr(image, pixel) \
		= (unsigned int)mlx_get_color_value(get_mlx_ptr(), color);
}
