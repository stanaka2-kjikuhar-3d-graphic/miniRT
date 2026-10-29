/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:39:37 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/18 10:54:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_PRIVATE_H
# define RAYTRACER_PRIVATE_H

# include "ray.h"
# include "color.h"
# include "vector.h"

# include "../renderer_private.h"

typedef struct s_weights
{
	float	local;
	float	reflected;
	float	refracted;
}	t_weights;

t_color		trace_ray(t_ray ray, int depth);
t_weights	calc_weights(t_ray const *ray, t_hit const *hit, int depth);
float		calc_sin2_transmitted(t_ray const *ray, t_hit const *hit);
t_ray		calc_reflect_ray(t_ray const *ray, t_hit const *hit);
t_ray		calc_refract_ray(t_ray const *ray, t_hit const *hit);
void		put_color_to_window_image(t_ivec2 pixel, t_color color);

#endif
