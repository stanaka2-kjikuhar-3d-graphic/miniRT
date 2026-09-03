/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:38:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 17:52:15 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "vector.h"

#include "./renderer_private.h"

void	render_pixel(t_ivec2 pixel)
{
	if (RENDER_ENGINE == RENDER_ENGINE_RAYTRACER)
		raytrace_pixel(pixel);
	else
		phong_pixel(pixel);
}
