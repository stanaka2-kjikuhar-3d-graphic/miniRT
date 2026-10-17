/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:39:37 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/17 16:34:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_PRIVATE_H
# define RAYTRACER_PRIVATE_H

# include "ray.h"
# include "color.h"

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

#endif
