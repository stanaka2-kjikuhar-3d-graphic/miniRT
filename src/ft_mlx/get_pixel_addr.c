/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:55:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/20 02:44:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "vector.h"

unsigned int	*get_pixel_addr(t_image *image, int x, int y)
{
	return ((unsigned int *)(image->pixel \
				+ y * image->line_size + x * image->bits_per_pixel / 8));
}
