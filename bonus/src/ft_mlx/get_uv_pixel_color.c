/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:51:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 19:29:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "color.h"

t_color	get_uv_pixel_color(t_image *image, float u, float v)
{
	int	x;
	int	y;

	if (u < 0.0f)
		x = 0;
	else if (1.0f <= u)
		x = image->width - 1;
	else
		x = (int)((float)image->width * u);
	if (v < 0.0f)
		y = 0;
	else if (1.0f <= v)
		y = image->height - 1;
	else
		y = (int)((float)image->height * v);
	return (convert_uint_to_color(*get_pixel_addr(image, x, y)));
}
