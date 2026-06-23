/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 21:35:12 by stanaka2         ###   ########.fr       */
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

t_hit	intersection(t_ray const *ray);
t_color	lighting(t_ray const *ray, t_hit const *hit);
bool	shadowing(t_hit const *hit, t_point_light const *light);

#endif
