/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:08:12 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 21:18:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stdbool.h>

# include "object.h"
# include "ray.h"

# define SHADOW_EPSILON 0.0001f // 1e-4

typedef struct s_hit
{
	t_object const	*object;
	float			t;
	t_vec3			point;
	t_vec2			uv;
	t_vec3			normal;
	t_color			color;
}	t_hit;

t_hit	find_closest_hit(t_ray const *ray);
bool	is_in_shadow(t_hit const *hit, t_vec3 light_dir, float light_dist);

#endif
