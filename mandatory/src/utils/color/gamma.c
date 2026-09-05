/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamma.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:07:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/16 15:22:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

#include "config.h"

static float	g_decoded[256];
static double	g_boundary[256];

void	init_gamma_lut(void)
{
	int	color;

	color = 0;
	while (color < 256)
	{
		g_decoded[color] = (float)pow(color / 255.0, GAMMA);
		g_boundary[color] = pow((color + 0.5) / 255.0, GAMMA);
		++color;
	}
}

float	decode_gamma(uint8_t gamma_encoded)
{
	return (g_decoded[gamma_encoded]);
}

uint8_t	encode_gamma(float linear)
{
	int	left;
	int	right;
	int	mid;

	if (isnan(linear) || linear <= 0.0f)
		return (0);
	if (1.0f <= linear)
		return (0xFF);
	left = 0;
	right = 255;
	while (right - left > 1)
	{
		mid = (right + left) / 2;
		if (g_decoded[mid] <= linear)
			left = mid;
		else
			right = mid;
	}
	if ((double)linear >= g_boundary[left])
		return ((uint8_t)left + 1);
	return ((uint8_t)left);
}
