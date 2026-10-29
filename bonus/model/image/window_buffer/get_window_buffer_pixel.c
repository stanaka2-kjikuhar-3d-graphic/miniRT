/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_buffer_pixel.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:55:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/18 08:11:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_buffer.h"
#include "vector.h"

#include "./window_buffer_private.h"
#include "../image_private.h"

unsigned int	get_window_buffer_pixel(\
	enum e_window_buffer_id id, t_ivec2 pixel)
{
	return (get_image_pixel(get_window_buffer(id), pixel));
}
