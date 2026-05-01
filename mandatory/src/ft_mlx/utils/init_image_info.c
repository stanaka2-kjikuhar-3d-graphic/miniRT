/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:54:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/13 01:02:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image_info(t_img *img, int width, int height)
{
	img->img_ptr = NULL;
	img->width = width;
	img->height = height;
	img->pixel = NULL;
	img->bits_per_pixel = COLOR_BIT_SIZE;
	img->size_line = width;
	img->endian = LITTLE_ENDIAN;
}
