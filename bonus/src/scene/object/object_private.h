/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 05:57:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIVATE_H
# define OBJECT_PRIVATE_H

typedef struct s_perp_cylinder
{
	t_vec3	ray;
	float	ray_len;
	t_vec3	to_cylinder;
	float	nearest_t;
	float	squared_nearest_dist;
	float	half_chord;
}	t_perp_cylinder;

bool	create_object(t_object const *object);
float	intersect_sphere(t_sphere const *sphere, t_ray const *ray);
float	intersect_plane(t_plane const *plane, t_ray const *ray);
float	intersect_cylinder(t_cylinder const *cylinder, t_ray const *ray);
float	intersect_circle(t_circle const *circle, t_ray const *ray);
t_vec3	calc_sphere_normal(\
			t_sphere const *sphere, t_ray const *ray, t_vec3 point);
t_vec3	calc_plane_normal(t_plane const *plane, t_ray const *ray);
t_vec3	calc_cylinder_normal(\
			t_cylinder const *cylinder, t_ray const *ray, t_vec3 point);
t_vec3	calc_circle_normal(t_circle const *circle, t_ray const *ray);
void	compute_onb(t_vec3 n, t_vec3 *tangent, t_vec3 *bitangent);

#endif
