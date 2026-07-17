/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:17:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/16 15:08:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "config.h"
#include "color.h"

uint8_t	encode_color(float color)
{
	if (GAMMA_MODE)
		return (encode_gamma(color));
	else
		return (encode_srgb(color));
}
