/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_lut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:11:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:27:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#include "./color_private.h"

void	init_color_lut(void)
{
	if (GAMMA_MODE)
		init_gamma_lut();
	else
		init_srgb_lut();
}
