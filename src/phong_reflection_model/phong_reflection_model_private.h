/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model_private.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 12:56:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_REFLECTION_MODEL_PRIVATE_H
# define PHONG_REFLECTION_MODEL_PRIVATE_H

# include <stdbool.h>

# include "object.h"
# include "ray.h"
# include "scene.h"
# include "color.h"

typedef struct s_hit
{
	t_object const	*object;
	double			t;
	t_dvec3			point;
	t_dvec3			normal;
	t_color			color;
}	t_hit;

t_hit	intersection(t_ray const *ray);
t_color	lighting(t_hit const *hit);
bool	shadowing(t_hit const *hit, t_light const *light);

#endif
