/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:06:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:17:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "renderer.h"
#include "./renderer_private.h"

void	render_pixel(t_ivec2 pixel)
{
	if (get_render_mode() == RENDER_MODE_PHONG)
		phong_pixel(pixel);
	else
		raytrace(pixel);
}
