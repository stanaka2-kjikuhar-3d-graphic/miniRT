/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_uv_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:50:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:06:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "../image_private.h"

unsigned int	get_image_uv_pixel(t_image const *image, t_vec2 uv)
{
	return (get_image_pixel(image, calc_image_uv_pixel(image, uv)));
}
