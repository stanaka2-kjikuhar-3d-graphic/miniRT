/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_factory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:01:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 16:40:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_FACTORY_H
# define LIGHT_FACTORY_H

# include <stdbool.h>

# include "color.h"
# include "vector.h"

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

bool	create_ambient_light(t_input_ambient_light const *input);
bool	create_uniform_infinite_light(\
			t_input_uniform_infinite_light const *input);
bool	create_point_light(t_input_point_light const *input);
bool	create_spot_light(t_input_spot_light const *input);
bool	create_directional_light(t_input_directional_light const *input);

#endif
