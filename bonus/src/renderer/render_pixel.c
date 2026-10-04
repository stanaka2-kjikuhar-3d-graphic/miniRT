/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:18:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/04 21:18:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "renderer.h"
#include "./renderer_private.h"

void	render_pixel(t_ivec2 pixel)
{
	enum e_render_mode	mode;

	mode = get_render_mode();
	if (mode == RENDER_MODE_RAYTRACE)
		raytrace_pixel(pixel);
	else if (mode == RENDER_MODE_PHONG)
		phong_pixel(pixel);
}
