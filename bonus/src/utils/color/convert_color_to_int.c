/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_to_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:27:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 18:23:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "color.h"

int	convert_color_to_int(t_color color)
{
	int						rgb;
	float const				channel[] = {color.r, color.g, color.b};
	enum e_color_channel	i;

	rgb = 0;
	i = RED;
	while (i <= BLUE)
	{
		if (channel[i] <= 0.0)
			rgb = (rgb << 8);
		else if (1.0 <= channel[i])
			rgb = (rgb << 8) | 0xFF;
		else
			rgb = (rgb << 8) | (int)round((0xFF * channel[i]));
		++i;
	}
	return (mlx_get_color_value(get_mlx_ptr(), rgb));
}
