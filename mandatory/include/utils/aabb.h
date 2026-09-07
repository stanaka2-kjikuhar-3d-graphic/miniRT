/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:42:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:41:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

# include <stdbool.h>

# include "matrix.h"
# include "range.h"

typedef struct s_aabb
{
	t_range	x;
	t_range	y;
	t_range	z;
}	t_aabb;

typedef struct s_aabb_info
{
	t_aabb	aabb;
	t_vec3	centroid;
	bool	has_bounded_aabb;
}	t_aabb_info;

t_aabb	initial_aabb(void);
t_aabb	transform_aabb(t_mat4 const *to_world, t_vec3 center, t_vec3 extent);
t_aabb	calc_aabb_from_extent(t_vec3 center, t_vec3 extent);
t_aabb	union_aabb(t_aabb a, t_aabb b);
float	mul_extent(float a, float b);
t_vec3	calc_aabb_centroid(t_aabb const *aabb);
bool	has_bounded_aabb(t_aabb const *aabb);

#endif
