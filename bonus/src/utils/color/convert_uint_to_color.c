/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint_to_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:23:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 18:33:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	convert_uint_to_color(unsigned int rgb)
{
	return ((t_color){\
		.r = (float)((rgb >> 16) & 0xff) / 255.0f, \
		.g = (float)((rgb >> 8) & 0xff) / 255.0f, \
		.b = (float)(rgb & 0xff) / 255.0f, \
	});
}
