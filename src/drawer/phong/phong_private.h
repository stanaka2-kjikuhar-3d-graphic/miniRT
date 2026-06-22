/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/22 20:46:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_PRIVATE_H
# define PHONG_PRIVATE_H

# include <stdbool.h>

# include "object.h"
# include "ray.h"
# include "light.h"
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
t_color	lighting(t_ray const *ray, t_hit const *hit);
bool	shadowing(t_hit const *hit, t_light const *light);

#endif
