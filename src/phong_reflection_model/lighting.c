/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:45:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 13:33:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "scene.h"
#include "./phong_reflection_model_private.h"

t_color	lighting(t_hit const *hit)
{
	t_color			color;
	t_light const	*light;
	double			diffuse;

	color = mul_color(hit->color, get_ambient_lighting()->radiance);
	light = get_light();
	if (!shadowing(hit, light))
	{
		diffuse = dvec3_dot(hit->normal, \
							dvec3_normalize(dvec3_sub(light->pos, hit->point)));
		if (diffuse > 0.0)
		{
			color = add_color(color, \
						mul_color(hit->color, \
							scale_color(diffuse * INTENSITY, light->radiance)));
		}
	}
	return (color);
}
