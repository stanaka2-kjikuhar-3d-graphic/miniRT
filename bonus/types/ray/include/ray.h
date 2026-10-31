/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 20:13:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/31 21:22:48 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "matrix.h"

typedef struct s_ray
{
	t_vec3	dir;
	t_vec3	origin;
}	t_ray;

t_ray	calc_ray(t_vec2 sample);
t_ray	transform_ray(t_mat4 const *transform, t_ray const *ray);

#endif
