/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:23:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:27:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "config.h"
#include "color.h"

#include "./color_private.h"

t_color	decode_color(unsigned int rgb)
{
	if (GAMMA_MODE)
	{
		return ((t_color){\
			.r = decode_gamma((uint8_t)((rgb >> 16) & 0xff)), \
			.g = decode_gamma((uint8_t)((rgb >> 8) & 0xff)), \
			.b = decode_gamma((uint8_t)(rgb & 0xff)), \
		});
	}
	else
	{
		return ((t_color){\
			.r = decode_srgb((uint8_t)((rgb >> 16) & 0xff)), \
			.g = decode_srgb((uint8_t)((rgb >> 8) & 0xff)), \
			.b = decode_srgb((uint8_t)(rgb & 0xff)), \
		});
	}
}
