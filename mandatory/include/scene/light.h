/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:51:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/31 22:02:56 by stanaka2         ###   ########.fr       */
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
	t_color	radiance;
	t_color	color;
	float	brightness;
	t_vec3	pos;
	t_vec3	dir;
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

// input
typedef struct s_input_ambient_light
{
	t_color	color;
	float	brightness;
}	t_input_ambient_light;

typedef struct s_input_uniform_infinite_light
{
	t_color	color;
	float	brightness;
}	t_input_uniform_infinite_light;

typedef struct s_input_point_light
{
	t_color	color;
	float	brightness;
	t_vec3	pos;
}	t_input_point_light;

typedef struct s_input_spot_light
{
	t_color	color;
	float	brightness;
	t_vec3	pos;
	t_vec3	dir;
	float	outer_angle;
}	t_input_spot_light;

typedef struct s_input_directional_light
{
	t_color	color;
	float	brightness;
	t_vec3	dir;
}	t_input_directional_light;

bool	get_next_light(t_light const **light);
void	cleanup_lights(void);
bool	create_ambient_light(t_input_ambient_light const *input);
bool	create_uniform_infinite_light(\
			t_input_uniform_infinite_light const *input);
bool	create_point_light(t_input_point_light const *input);
bool	create_spot_light(t_input_spot_light const *input);
bool	create_directional_light(t_input_directional_light const *input);
float	calc_point_light_attenuation(t_point_light const *light, float dist);
float	calc_spot_light_attenuation(\
			t_spot_light const *light, float dist, float dot);
bool	check_cutoff(t_color radiance, float attenuation);

#endif
