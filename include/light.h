/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:51:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:57:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include <stddef.h>
# include <stdbool.h>

# include "color.h"
# include "vector.h"

typedef struct s_ambient_light
{
	t_color	radiance;
	t_color	color;
	double	brightness;
}	t_ambient_light;

enum e_light_type
{
	POINT_LIGHT,
	SPOT_LIGHT
};

typedef struct s_light
{
	enum e_light_type	type;
	t_dvec3				pos;
	t_color				radiance;
	t_color				color;
	double				brightness;
	struct s_spot_light
	{
		t_dvec3	dir;
		double	angle;
	}	spot;
}	t_light;

// input
typedef struct s_input_ambient
{
	t_color	color;
	double	brightness;
}	t_input_ambient;

typedef struct s_input_point_light
{
	t_dvec3	pos;
	t_color	color;
	double	brightness;
}	t_input_point_light;

typedef struct s_input_spot_light
{
	t_dvec3	pos;
	t_color	color;
	double	brightness;
	t_dvec3	dir;
	double	angle;
}	t_input_spot_light;

t_ambient_light const	*get_ambient_light(void);
void					set_ambient_light(t_input_ambient const *input);
bool					get_next_light(t_light const **light);
bool					add_point_light(t_input_point_light const *input);
bool					add_spot_light(t_input_spot_light const *input);
bool					allocate_lights(size_t add_count);
void					cleanup_lights(void);

#endif