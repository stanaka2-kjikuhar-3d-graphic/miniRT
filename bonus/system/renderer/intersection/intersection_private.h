/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:09:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/04 21:59:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_PRIVATE_H
# define INTERSECTION_PRIVATE_H

# include <stdbool.h>

# include "ray.h"
# include "object.h"
# include "primitive.h"
# include "aabb.h"

# include "../renderer_private.h"

typedef struct s_quadric_coeffs
{
	float	a;
	float	b;
	float	c;
}	t_quadric_coeffs;

typedef struct s_roots
{
	int		count;
	float	t[2];
}	t_roots;

void	bvh_intersection(t_hit *hit, t_ray const *ray);
void	infinite_objects_intersection(t_hit *hit, t_ray const *ray);
bool	bvh_shading(t_ray const *ray, float dist);
bool	infinite_objects_shading(t_ray const *ray, float dist);
float	calc_object_intersection(\
			t_object const *object, t_ray const *ray);
float	calc_primitive_intersection(\
			t_primitive const *prim, t_ray const *ray);
float	calc_planar_intersection(\
			t_primitive const *prim, t_ray const *local);
float	calc_quadric_intersection(\
			t_primitive const *prim, t_ray const *local);
float	calc_aabb_intersection(t_aabb const *aabb, t_ray const *ray);

#endif
