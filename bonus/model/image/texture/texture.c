/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:49:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "dynamic_array.h"

#include "./texture_private.h"
#include "../image_private.h"

static t_dynamic_array	g_textures = (t_dynamic_array){\
										.type_size = sizeof(t_texture) \
									};

t_dynamic_array	*get_mutable_texture_array(void)
{
	return (&g_textures);
}

t_image	*get_texture(t_texture_id id)
{
	return (((t_texture *)access_dynamic_array(\
				&g_textures, get_texture_index(id)))->image);
}
