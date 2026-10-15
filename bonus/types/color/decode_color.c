/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:23:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/03 22:27:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "config.h"
#include "color.h"

#include "./color_private.h"

t_color	decode_color(unsigned int rgb)
{
	if (COLOR_ENCODING_MODE == ENCODING_SRGB)
	{
		return ((t_color){\
			.r = decode_srgb((uint8_t)((rgb >> 16) & 0xff)), \
			.g = decode_srgb((uint8_t)((rgb >> 8) & 0xff)), \
			.b = decode_srgb((uint8_t)(rgb & 0xff)), \
		});
	}
	else
	{
		return ((t_color){\
			.r = decode_gamma((uint8_t)((rgb >> 16) & 0xff)), \
			.g = decode_gamma((uint8_t)((rgb >> 8) & 0xff)), \
			.b = decode_gamma((uint8_t)(rgb & 0xff)), \
		});
	}
}
