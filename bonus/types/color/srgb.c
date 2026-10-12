/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:35:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/16 15:21:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdint.h>

#define TABLE_SIZE 4096

static double	g_boundary[256];
static float	g_decoded[256];
static uint8_t	g_encoded[TABLE_SIZE];

static double	decode_srgb_piecewise_function(double srgb);

void	init_srgb_lut(void)
{
	int	color;
	int	i;

	color = 0;
	while (color < 256)
	{
		g_decoded[color] \
			= (float)decode_srgb_piecewise_function(color / 255.0);
		g_boundary[color] \
			= decode_srgb_piecewise_function((color + 0.5) / 255.0);
		++color;
	}
	color = 0;
	i = 0;
	while (i < TABLE_SIZE)
	{
		while (color < 255 && g_boundary[color] <= (double)i / TABLE_SIZE)
			++color;
		g_encoded[i++] = (uint8_t)color;
	}
}

static double	decode_srgb_piecewise_function(double srgb)
{
	if (srgb <= 0.04045)
		return (srgb / 12.92);
	else
		return (pow((srgb + 0.055) / 1.055, 2.4));
}

float	decode_srgb(uint8_t srgb)
{
	return (g_decoded[srgb]);
}

uint8_t	encode_srgb(float linear)
{
	uint8_t	color;

	if (isnan(linear) || linear <= 0.0f)
		return (0);
	if (1.0f <= linear)
		return (0xFF);
	color = g_encoded[(int)(linear * (float)TABLE_SIZE)];
	if ((double)linear >= g_boundary[color])
		++color;
	return (color);
}

// #include <stdlib.h>

// int	test_table_size(void)
// {
// 	int		table_size;
// 	uint8_t	*float_decoded;
// 	int		color;
// 	int		i;

// 	init_srgb_lut();
//	float_decoded = NULL;
// 	table_size = 512;
// 	while (table_size < 32768)
// 	{
// 		free(float_decoded);
// 		table_size *= 2;
// 		float_decoded = malloc(sizeof(uint8_t) * table_size);
// 		if (float_decoded == NULL)
// 			return (-1);
// 		color = 0;
// 		i = 0;
// 		while (i < table_size)
// 		{
// 			while (color <= 254 && g_boundary[color] <= (double)i / table_size)
// 				++color;
// 			if (i != 0 && color - float_decoded[i - 1] >= 2)
// 				break ;
// 			float_decoded[i++] = (uint8_t)color;
// 		}
// 		if (i == table_size)
// 		{
// 			free(float_decoded);
// 			return (table_size);
// 		}
// 	}
// 	free(float_decoded);
// 	return (-1);
// }
