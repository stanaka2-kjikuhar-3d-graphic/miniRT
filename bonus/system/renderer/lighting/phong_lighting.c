/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 02:56:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:23:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "color.h"
#include "ray.h"
#include "light.h"

#include "./lighting_private.h"
#include "../renderer_private.h"

t_color	phong_lighting(t_ray const *ray, t_hit const *hit)
{
	t_color			color;
	t_light const	*light;
	size_t			light_count;
	size_t			i;

	color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	light_count = get_light_count();
	i = 0;
	while (i < light_count)
	{
		light = get_light_by_index(i);
		if (light->type == AMBIENT_LIGHT)
			phong_lighting_ambient(&color, hit, &(light->ambient));
		else if (light->type == POINT_LIGHT)
			phong_lighting_point(&color, ray, hit, &(light->point));
		else if (light->type == SPOT_LIGHT)
			phong_lighting_spot(&color, ray, hit, &(light->spot));
		else if (light->type == DIRECTIONAL_LIGHT)
			phong_lighting_directional(&color, ray, hit, &(light->directional));
		++i;
	}
	return (color);
}
