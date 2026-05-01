/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:37:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/04 16:49:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dvec2	dvec2(double x, double y)
{
	t_dvec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_dvec2	dvec2_normalize(t_dvec2 v)
{
	const double	len = dvec2_length(v);

	if (len == 0.0)
		return (v);
	return (dvec2_scale(v, 1.0 / len));
}

double	dvec2_length(t_dvec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_dvec2	dvec2_scale(t_dvec2 v, double s)
{
	t_dvec2	scale;

	scale.x = s * v.x;
	scale.y = s * v.y;
	return (scale);
}

t_dvec2	dvec2_rotate(t_dvec2 v, double radian)
{
	t_dvec2	rotate;

	rotate.x = v.x * cos(radian) + v.y * -sin(radian);
	rotate.y = v.x * sin(radian) + v.y * cos(radian);
	return (rotate);
}
