/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:51:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/14 07:05:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <stddef.h>
# include <stdbool.h>

# include "color.h"
# include "vector.h"

typedef struct s_dist_attenuation
{
	float	range;
	float	constant;
	float	linear;
	float	quadratic;
}	t_dist_attenuation;

typedef struct s_ambient_light
{
	t_color	radiance;
	t_color	color;
	float	brightness;
}	t_ambient_light;

typedef struct s_uniform_infinite_light
{
	t_color	radiance;
	t_color	color;
	float	brightness;
}	t_uniform_infinite_light;

typedef struct s_point_light
{
	t_color				radiance;
	t_color				color;
	float				brightness;
	t_vec3				pos;
	t_dist_attenuation	attenuation;
}	t_point_light;

typedef struct s_spot_light
{
	t_color				radiance;
	t_color				color;
	float				brightness;
	t_vec3				pos;
	t_vec3				dir;
	struct s_spot_angle
	{
		float	outer;
		float	cos_half_outer;
		float	inner;
		float	cos_half_inner;
	}	angle;
	t_dist_attenuation	attenuation;
}	t_spot_light;

typedef struct s_directional_light
{
	t_color	radiance;
	t_color	color;
	float	brightness;
	t_vec3	dir;
}	t_directional_light;

enum e_light_type
{
	AMBIENT_LIGHT,
	UNIFORM_INFINITE_LIGHT,
	POINT_LIGHT,
	SPOT_LIGHT,
	DIRECTIONAL_LIGHT
};

typedef struct s_light
{
	size_t				id;
	enum e_light_type	type;
	union
	{
		t_ambient_light				ambient;
		t_uniform_infinite_light	uniform_infinite;
		t_point_light				point;
		t_spot_light				spot;
		t_directional_light			directional;
	};
}	t_light;

t_light const	*get_light(size_t i);
size_t			get_light_count(void);
bool			create_light(size_t *id);
void			cleanup_lights(void);
void			set_ambient_light(size_t id);
void			set_directional_light(size_t id, t_vec3 dir);
void			set_point_light(size_t id, t_vec3 pos);
void			set_spot_light(\
					size_t id, t_vec3 pos, t_vec3 dir, float outer_angle);
void			set_uniform_infinite_light(size_t id);
void			set_ambient_light_radiance(\
					size_t id, t_color color, float brightness);
void			set_directional_light_radiance(\
					size_t id, t_color color, float brightness);
void			set_point_light_radiance(\
					size_t id, t_color color, float brightness);
void			set_spot_light_radiance(\
					size_t id, t_color color, float brightness);
void			set_uniform_infinite_light_radiance(\
					size_t id, t_color color, float brightness);
#endif
