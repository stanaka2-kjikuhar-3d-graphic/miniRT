/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:16:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 03:41:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*get_pixel_addr(const t_img *img, const int x, const int y)
{
	char	*pixel_addr;

	pixel_addr = (img->pixel \
		+ (y * img->size_line) + (x * (img->bits_per_pixel / 8)));
	return ((unsigned int *)pixel_addr);
}
