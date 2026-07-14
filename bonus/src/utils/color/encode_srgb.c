/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_srgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:05:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 00:16:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "ft_error.h"
#include "color.h"

static double	g_boundary[256];
static uint8_t	*g_srgb_encoded;
static int		g_table_size;

static void	init_boundary_lut(void);

bool	init_srgb_encoded_lut(void)
{
	int	color;
	int	i;

	init_boundary_lut();
	g_table_size = 512;
	while (g_table_size < 32768)
	{
		free(g_srgb_encoded);
		g_table_size *= 2;
		g_srgb_encoded = malloc(sizeof(uint8_t) * g_table_size);
		if (g_srgb_encoded == NULL)
		{
			print_errno();
			return (false);
		}
		color = 0;
		i = 0;
		while (i < g_table_size)
		{
			while (color <= 254 && g_boundary[color] <= (double)i / g_table_size)
				++color;
			if (i != 0 && color - g_srgb_encoded[i - 1] >= 2)
				break ;
			g_srgb_encoded[i++] = (uint8_t)color;
		}
		if (i == g_table_size)
			return (true);
	}
	cleanup_srgb_encoded_lut();
	print_error("");
	return (false);
}

static void	init_boundary_lut(void)
{
	double	color;
	double	srgb;

	color = 0.5;
	while (color < 255.0)
	{
		srgb = color / 255.0;
		if (srgb <= 0.04045)
			g_boundary[(int)color] = srgb / 12.92;
		else
			g_boundary[(int)color] = pow((srgb + 0.055) / 1.055, 2.4);
		color += 1.0;
	}
	g_boundary[255] = INFINITY;
}

void	cleanup_srgb_encoded_lut(void)
{
	free(g_srgb_encoded);
	g_srgb_encoded = NULL;
}

uint8_t	encode_srgb(float linear)
{
	uint8_t	color;

	if (isnan(linear) || linear <= 0.0f)
		return (0);
	if (1.0f <= linear)
		return (0xFF);
	color = g_srgb_encoded[(int)(linear * (float)g_table_size)];
	if ((double)linear >= g_boundary[color])
		++color;
	return (color);
}
