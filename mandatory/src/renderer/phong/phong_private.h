/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:37:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_PRIVATE_H
# define PHONG_PRIVATE_H

# include <stdbool.h>

# include "object.h"
# include "ray.h"
# include "light.h"
# include "color.h"

# define SHADOW_EPSILON 0.0001f // 1e-4

typedef struct s_hit
{
	t_object const	*object;
	float			t;
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}	t_hit;

t_hit	phong_intersection(t_ray const *ray);
void	bvh_intersection(t_hit *hit, t_ray const *ray);
void	infinite_objects_intersection(t_hit *hit, t_ray const *ray);
bool	bvh_shading(t_ray const *ray, float dist);
bool	infinite_objects_shading(t_ray const *ray, float dist);
t_color	phong_lighting(t_hit const *hit);
void	phong_lighting_ambient(t_color *color, \
			t_hit const *hit, t_ambient_light const *light);
void	phong_lighting_point(\
			t_color *color, t_hit const *hit, t_point_light const *light);
bool	phong_shading(\
			t_hit const *hit, t_vec3 light_dir, float light_dist);

#endif
