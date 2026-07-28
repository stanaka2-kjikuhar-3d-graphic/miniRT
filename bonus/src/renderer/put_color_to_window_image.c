/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_window_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:15:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "vector.h"
#include "color.h"

void	put_color_to_window_image(t_ivec2 pixel, t_color color)
{
	put_color(get_image(IMG_WINDOW), pixel, encode_color(color));
}
