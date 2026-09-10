/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/10 21:27:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_PRIVATE_H
# define PHONG_PRIVATE_H

# include <stdbool.h>

# include "ray.h"
# include "light.h"
# include "color.h"

# include "intersection.h"

t_color	phong_lighting(t_ray const *ray, t_hit const *hit);
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

#endif
