/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:51:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 14:05:48 by stanaka2         ###   ########.fr       */
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

typedef struct s_light
{
	t_dvec3	pos;
	t_color	radiance;
	t_color	color;
	double	brightness;
}	t_light;

t_ambient_light const	*get_ambient_light(void);
void						set_ambient_light(\
								t_color color, double brightness);
bool						get_next_light(t_light const **light);
bool						add_light(\
								t_dvec3 pos, t_color color, double brightness);
bool						allocate_lights(size_t add_count);
void						cleanup_lights(void);

#endif