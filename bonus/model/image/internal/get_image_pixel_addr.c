/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_pixel_addr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:55:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/18 02:18:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "../image_private.h"

unsigned int	*get_image_pixel_addr(t_image *image, t_ivec2 pixel)
{
	return ((unsigned int *)(image->pixel \
				+ pixel.y * image->line_size \
				+ pixel.x * image->bits_per_pixel / 8));
}
