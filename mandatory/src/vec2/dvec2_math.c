/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec2_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:37:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/24 11:16:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_dvec2	dvec2_add(t_dvec2 a, t_dvec2 b)
{
	t_dvec2	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

t_dvec2	dvec2_sub(t_dvec2 a, t_dvec2 b)
{
	t_dvec2	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	return (sub);
}

double	dvec2_dot(t_dvec2 a, t_dvec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

double	dvec2_cross(t_dvec2 a, t_dvec2 b)
{
	return (a.x * b.y - a.y * b.x);
}
