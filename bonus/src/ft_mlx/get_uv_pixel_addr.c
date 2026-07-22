/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_pixel_addr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:50:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/19 18:57:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "vector.h"

unsigned int	*get_uv_pixel_addr(t_image *image, t_vec2 uv)
{
	return (get_pixel_addr(image, calc_uv_pixel(image, uv)));
}
