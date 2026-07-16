/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:12:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/16 15:08:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "config.h"
#include "color.h"

float	decode_color(uint8_t color)
{
	if (GAMMA_MODE)
		return (decode_gamma(color));
	else
		return (decode_srgb(color));
}
