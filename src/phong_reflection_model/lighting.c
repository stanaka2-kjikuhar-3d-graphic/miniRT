/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:45:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 18:29:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "color.h"
#include "scene.h"
#include "./phong_reflection_model_private.h"

t_color	lighting(t_hit const *hit)
{
	t_light const *const	lights = get_lights();
	size_t const			count = get_lights_count();
	t_color					color;
	size_t					i;
	double					diffuse;

	color = mul_color(hit->color, get_ambient_lighting()->radiance);
	i = 0;
	while (i < count)
	{
		if (!shadowing(hit, &(lights[i])))
		{
			diffuse = dvec3_dot(hit->normal, \
						dvec3_normalize(dvec3_sub(lights[i].pos, hit->point)));
			if (diffuse > 0.0)
			{
				color = add_color(color, mul_color(hit->color, \
						scale_color(diffuse * INTENSITY, lights[i].radiance)));
			}
		}
		++i;
	}
	return (color);
}
