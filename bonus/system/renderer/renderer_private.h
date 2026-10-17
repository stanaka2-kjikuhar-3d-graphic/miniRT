/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 16:34:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_PRIVATE_H
# define RENDERER_PRIVATE_H

# include <stdbool.h>

# include "config.h"
# include "object.h"
# include "vector.h"
# include "color.h"
# include "aabb.h"

# define SHADOW_EPSILON 0.0001f // 1e-4

typedef struct s_hit
{
	t_object const	*object;
	float			t;
	t_vec3			point;
	t_vec2			uv;
	t_vec3			normal;
	t_color			color;
	bool			is_front_face;
}	t_hit;

bool	check_render_flag(void);
void	raytrace(t_ivec2 pixel);
void	put_color_to_window_image(t_ivec2 pixel, t_color color);

// intersection
t_hit	find_closest_hit(t_ray const *ray);
bool	is_in_shadow(t_hit const *hit, t_vec3 light_dir, float light_dist);
// surface
t_vec2	calc_object_uv(t_object const *object, t_vec3 point);
t_color	calc_object_color(t_object const *object, t_vec2 uv);
t_vec3	calc_object_normal(\
			t_object const *object, t_ray const *ray, t_vec3 point);
t_mat3	calc_object_tbn(t_object const *object, t_vec3 point, t_vec3 normal);
t_vec3	calc_bump_mapping(t_object const *object, t_vec2 uv, t_mat3 const *tbn);
t_vec3	calc_normal_mapping(\
			t_object const *object, t_vec2 uv, t_mat3 const *tbn);

// lighting
t_color	phong_lighting(t_ray const *ray, t_hit const *hit);

#endif
