/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_ambient.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:39:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 21:28:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "light.h"

#include "../lighting_private.h"

static t_color	calc_ambient_color(\
	t_hit const *hit, t_ambient_light const *light);

void	phong_lighting_ambient(t_color *color, \
	t_hit const *hit, t_ambient_light const *light)
{
	*color = add_color(*color, calc_ambient_color(hit, light));
}

static t_color	calc_ambient_color(\
	t_hit const *hit, t_ambient_light const *light)
{
	t_color	ambient;

	ambient = light->radiance;
	return (mul_color(hit->color, ambient));
}
