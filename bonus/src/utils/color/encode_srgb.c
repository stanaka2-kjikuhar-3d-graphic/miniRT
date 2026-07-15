/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_srgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:05:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 13:58:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

#include "color.h"

#define TABLE_SIZE 4096

static double	g_boundary[256];
static uint8_t	g_srgb_encoded[TABLE_SIZE];

static void	init_boundary_lut(void);

void	init_srgb_encoded_lut(void)
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
		g_srgb_encoded[i++] = (uint8_t)color;
	}
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

uint8_t	encode_srgb(float linear)
{
	uint8_t	color;

	if (isnan(linear) || linear <= 0.0f)
		return (0);
	if (1.0f <= linear)
		return (0xFF);
	color = g_srgb_encoded[(int)(linear * (float)TABLE_SIZE)];
	if ((double)linear >= g_boundary[color])
		++color;
	return (color);
}

// #include <stdlib.h>

// int	test_table_size(void)
// {
// 	int		table_size;
// 	uint8_t	*srgb_encoded;
// 	int		color;
// 	int		i;

// 	init_boundary_lut();
// 	table_size = 512;
// 	while (table_size < 32768)
// 	{
// 		free(srgb_encoded);
// 		table_size *= 2;
// 		srgb_encoded = malloc(sizeof(uint8_t) * table_size);
// 		if (srgb_encoded == NULL)
// 			return (-1);
// 		color = 0;
// 		i = 0;
// 		while (i < table_size)
// 		{
// 			while (color <= 254 && g_boundary[color] <= (double)i / table_size)
// 				++color;
// 			if (i != 0 && color - srgb_encoded[i - 1] >= 2)
// 				break ;
// 			srgb_encoded[i++] = (uint8_t)color;
// 		}
// 		if (i == table_size)
// 		{
// 			free(srgb_encoded);
// 			return (table_size);
// 		}
// 	}
// 	free(srgb_encoded);
// 	return (-1);
// }
