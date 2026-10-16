/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_light.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:41:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 07:31:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_LIGHT_H
# define LOADER_LIGHT_H

# include <stdbool.h>

# include "color.h"
# include "vector.h"

typedef struct s_ambient_light_input
{
	t_color	color;
	float	brightness;
}	t_ambient_light_input;

typedef struct s_uniform_infinite_light_input
{
	t_color	color;
	float	brightness;
}	t_uniform_infinite_light_input;

typedef struct s_point_light_input
{
	t_color	color;
	float	brightness;
	t_vec3	pos;
}	t_point_light_input;

typedef struct s_spot_light_input
{
	t_color	color;
	float	brightness;
	t_vec3	pos;
	t_vec3	dir;
	float	outer_angle;
}	t_spot_light_input;

typedef struct s_directional_light_input
{
	t_color	color;
	float	brightness;
	t_vec3	dir;
}	t_directional_light_input;

#endif
