/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_srgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:35:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 00:06:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

static float	g_srgb_decoded[256];

void	init_srgb_decode_lut(void)
{
	int		color;
	double	srgb;

	color = 0;
	while (color < 256)
	{
		srgb = (double)color / 255.0;
		if (srgb <= 0.04045)
			g_srgb_decoded[color] = (float)(srgb / 12.92);
		else
			g_srgb_decoded[color] = (float)(pow((srgb + 0.055) / 1.055, 2.4));
		++color;
	}
}

float	decode_srgb(uint8_t srgb)
{
	return (g_srgb_decoded[srgb]);
}