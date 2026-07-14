/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint_to_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:23:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/14 15:29:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "color.h"

t_color	convert_uint_to_color(unsigned int rgb)
{
	return ((t_color){\
		.r = decode_srgb((uint8_t)((rgb >> 16) & 0xff)), \
		.g = decode_srgb((uint8_t)((rgb >> 8) & 0xff)), \
		.b = decode_srgb((uint8_t)(rgb & 0xff)), \
	});
}
