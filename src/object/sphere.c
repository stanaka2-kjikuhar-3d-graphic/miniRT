/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:44:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 23:49:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"

static t_sphere	g_sphere;

t_sphere const	*get_sphere(void)
{
	return (&g_sphere);
}

void	set_sphere_pos(t_dvec3 pos)
{
	g_sphere.pos = pos;
}

void	set_sphere_diameter(double diameter)
{
	g_sphere.diameter = diameter;
}
