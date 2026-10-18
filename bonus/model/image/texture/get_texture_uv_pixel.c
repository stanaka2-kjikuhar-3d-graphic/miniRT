/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_uv_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:50:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:06:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "vector.h"

#include "./texture_private.h"
#include "../image_private.h"

unsigned int	get_texture_uv_pixel(t_texture_id id, t_vec2 uv)
{
	t_image const	*image;

	image = get_texture(id);
	return (get_image_uv_pixel(image, uv));
}
