/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 08:29:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:49:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "texture.h"

#include "./texture_private.h"
#include "../image_private.h"

t_ivec2	get_texture_size(t_texture_id id)
{
	t_image const	*image;

	image = get_texture(id);
	return ((t_ivec2){.width = image->width, .height = image->height});
}
