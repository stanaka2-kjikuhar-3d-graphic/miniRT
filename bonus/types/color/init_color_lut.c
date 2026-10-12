/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_lut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:11:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/03 22:27:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "./color_private.h"

void	init_color_lut(void)
{
	if (COLOR_ENCODING_MODE == ENCODING_SRGB)
		init_srgb_lut();
	else
		init_gamma_lut();
}
