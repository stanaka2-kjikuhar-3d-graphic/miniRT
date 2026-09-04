/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint_to_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:29:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:31:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "color.h"

t_color	convert_uint_to_color(unsigned int rgb)
{
	return ((t_color){\
		.r = (uint8_t)((rgb >> 16) & 0xff) / 255.0f, \
		.g = (uint8_t)((rgb >> 8) & 0xff) / 255.0f, \
		.b = (uint8_t)(rgb & 0xff) / 255.0f, \
	});
}
