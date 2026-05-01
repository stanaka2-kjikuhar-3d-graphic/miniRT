/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:38:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/06 16:04:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ivec2	ivec2(int x, int y)
{
	t_ivec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

double	ivec2_length(t_ivec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_ivec2	ivec2_scale(t_ivec2 v, int s)
{
	t_ivec2	scale;

	scale.x = s * v.x;
	scale.y = s * v.y;
	return (scale);
}
