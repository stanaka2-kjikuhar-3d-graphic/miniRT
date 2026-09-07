/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:51:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:34:03 by stanaka2         ###   ########.fr       */
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

typedef struct s_point_light
{
	t_color				radiance;
	t_color				color;
	float				brightness;
	t_vec3				pos;
	t_dist_attenuation	attenuation;
}	t_point_light;

enum e_light_type
{
	AMBIENT_LIGHT,
	POINT_LIGHT
};

typedef struct s_light
{
	enum e_light_type	type;
	union
	{
		t_ambient_light				ambient;
		t_point_light				point;
	};
}	t_light;

// input
typedef struct s_input_ambient_light
{
	t_color	color;
	float	brightness;
}	t_input_ambient_light;

typedef struct s_input_point_light
{
	t_color	color;
	float	brightness;
	t_vec3	pos;
}	t_input_point_light;

bool	get_next_light(t_light const **light);
void	cleanup_lights(void);
bool	create_ambient_light(t_input_ambient_light const *input);
bool	create_point_light(t_input_point_light const *input);
float	calc_point_light_attenuation(t_point_light const *light, float dist);
bool	check_cutoff(t_color radiance, float attenuation);

#endif
