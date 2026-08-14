/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_aabb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:07:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 13:07:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "aabb.h"
#include "range.h"

t_aabb	initial_aabb(void)
{
	return ((t_aabb){
		.x = (t_range){.min = INFINITY, .max = -INFINITY}, \
		.y = (t_range){.min = INFINITY, .max = -INFINITY}, \
		.z = (t_range){.min = INFINITY, .max = -INFINITY} \
	});
}
