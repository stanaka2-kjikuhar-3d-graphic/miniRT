/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:06:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 21:32:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_PRIVATE_H
# define LIGHTING_PRIVATE_H

# include <stdbool.h>

# include "ray.h"
# include "light.h"
# include "color.h"

# include "../renderer_private.h"

void	phong_lighting_ambient(t_color *color, \
			t_hit const *hit, t_ambient_light const *light);
void	phong_lighting_point(t_color *color, \
			t_ray const *ray, t_hit const *hit, t_point_light const *light);
void	phong_lighting_spot(t_color *color, \
			t_ray const *ray, t_hit const *hit, t_spot_light const *light);
void	phong_lighting_directional(t_color *color, t_ray const *ray, \
			t_hit const *hit, t_directional_light const *light);
float	calc_specular_dot(\
			t_ray const *ray, t_hit const *hit, t_vec3 to_light);

float	calc_point_light_attenuation(t_point_light const *light, float dist);
float	calc_spot_light_attenuation(\
			t_spot_light const *light, float dist, float dot);
bool	check_cutoff(t_color radiance, float attenuation);
float	calc_dist_attenuation(\
			t_dist_attenuation const *attenuation, float dist);

#endif
