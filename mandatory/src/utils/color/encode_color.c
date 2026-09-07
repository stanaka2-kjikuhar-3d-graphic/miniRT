/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:27:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/30 19:23:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>

#include "config.h"
#include "color.h"

#include "./color_private.h"

int	encode_color(t_color color)
{
	int						rgb;
	uint8_t					encoded;
	enum e_color_channel	i;

	rgb = 0;
	i = RED;
	while (i <= BLUE)
	{
		if (COLOR_ENCODING_MODE == ENCODING_SRGB)
			encoded = encode_srgb(color.channels[i]);
		else
			encoded = encode_gamma(color.channels[i]);
		rgb = (rgb << 8) | (int)(encoded);
		++i;
	}
	return (rgb);
}
