/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_window_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:24:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_buffer.h"
#include "vector.h"
#include "color.h"

void	put_color_to_window_image(t_ivec2 pixel, t_color color)
{
	put_color(MAIN_WINDOW_BUFFER, pixel, encode_color(color));
}
