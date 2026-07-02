/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 02:56:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:10:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "../phong_private.h"

t_color	phong_lighting(t_ray const *ray, t_hit const *hit)
{
	t_color			color;
	t_light const	*light;

	color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	light = NULL;
	while (get_next_light(&light))
	{
		if (light->type == AMBIENT_LIGHT)
			phong_lighting_ambient(&color, hit, &(light->ambient));
		else if (light->type == POINT_LIGHT)
			phong_lighting_point(&color, ray, hit, &(light->point));
		else if (light->type == SPOT_LIGHT)
			phong_lighting_spot(&color, ray, hit, &(light->spot));
	}
	return (color);
}
