/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 20:13:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 19:25:22 by stanaka2         ###   ########.fr       */
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

t_ray	transform_ray(t_mat4 const *transform, t_ray const *ray);

#endif
