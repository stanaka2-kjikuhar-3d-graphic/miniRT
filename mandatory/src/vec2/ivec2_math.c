/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:38:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/24 11:16:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b)
{
	t_ivec2	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b)
{
	t_ivec2	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	return (sub);
}

int	ivec2_dot(t_ivec2 a, t_ivec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

int	ivec2_cross(t_ivec2 a, t_ivec2 b)
{
	return (a.x * b.y - a.y * b.x);
}
