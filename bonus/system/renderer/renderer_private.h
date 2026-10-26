/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:24:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_PRIVATE_H
# define RENDERER_PRIVATE_H

# include <stdbool.h>

# include "object.h"
# include "vector.h"
# include "color.h"
# include "material.h"
# include "ray.h"

# define SHADOW_EPSILON 0.0001f // 1e-4

typedef struct s_hit
{
	t_object const		*object;
	float				t;
	t_material const	*material;
	t_vec3				point;
	t_vec2				uv;
	t_vec3				normal;
	t_color				color;
	bool				is_front_face;
}	t_hit;

bool	check_render_flag(void);
void	raytrace(t_ivec2 pixel);

// intersection
t_hit	find_closest_hit(t_ray const *ray);
bool	is_in_shadow(t_hit const *hit, t_vec3 light_dir, float light_dist);
// surface
void	set_hit_record(t_ray const *ray, t_hit *hit);

// lighting
t_color	phong_lighting(t_ray const *ray, t_hit const *hit);

#endif
