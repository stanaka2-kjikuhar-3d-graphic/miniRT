/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_bounded_aabb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 01:11:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 01:15:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "object.h"

bool	has_bounded_aabb(t_aabb const *aabb)
{
	return (isfinite(aabb->x.min) && isfinite(aabb->x.max)
		&& isfinite(aabb->y.min) && isfinite(aabb->y.max)
		&& isfinite(aabb->z.min) && isfinite(aabb->z.max));
}
