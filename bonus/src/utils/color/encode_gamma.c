/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_gamma.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:07:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 14:09:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

#include "color.h"

static double	g_boundary[255];
static uint8_t	g_gamma_encoded[256];

static void	init_boundary_lut(void);

void	init_gamma_encoded_lut(void)
{
	int	color;
	int	i;

	init_boundary_lut();
	color = 0;
	i = 0;
	while (i < TABLE_SIZE)
	{
		while (color <= 254 && g_boundary[color] <= (double)i / TABLE_SIZE)
			++color;
		g_gamma_encoded[i++] = (uint8_t)color;
	}
}

static void	init_boundary_lut(void)
{
	double	color;
	double	gamma;

	color = 0.5;
	while (color < 255.0)
	{
		gamma = color / 255.0;
		if (gamma <= 0.04045)
			g_boundary[(int)color] = gamma / 12.92;
		else
			g_boundary[(int)color] = pow((gamma + 0.055) / 1.055, 2.4);
		color += 1.0;
	}
	g_boundary[255] = INFINITY;
}

uint8_t	encode_gamma(float linear)
{
	uint8_t	color;

	if (isnan(linear) || linear <= 0.0f)
		return (0);
	if (1.0f <= linear)
		return (0xFF);
	color = g_gamma_encoded[(int)(linear * (float)TABLE_SIZE)];
	if ((double)linear >= g_boundary[color])
		++color;
	return (color);
}