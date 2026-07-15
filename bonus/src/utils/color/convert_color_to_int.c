/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_to_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:27:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 14:07:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "color.h"

int	convert_color_to_int(t_color color)
{
	int						rgb;
	float const				channel[] = {color.r, color.g, color.b};
	uint8_t					srgb;
	enum e_color_channel	i;

	rgb = 0;
	i = RED;
	while (i <= BLUE)
	{
		srgb = encode_srgb(channel[i]);
		rgb = (rgb << 8) | (int)(srgb);
		++i;
	}
	return (mlx_get_color_value(get_mlx_ptr(), rgb));
}
