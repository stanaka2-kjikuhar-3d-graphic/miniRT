/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 15:21:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIVATE_H
# define OBJECT_PRIVATE_H

typedef struct s_perp_cylinder
{
	t_dvec3	ray;
	double	ray_len;
	t_dvec3	to_cylinder;
	double	nearest_t;
	double	squared_nearest_dist;
	double	half_chord;
}	t_perp_cylinder;

double	intersect_sphere(t_sphere const *sphere, t_ray const *ray);
double	intersect_plane(t_plane const *plane, t_ray const *ray);
double	intersect_cylinder(t_cylinder const *cylinder, t_ray const *ray);
double	intersect_circle(t_circle const *circle, t_ray const *ray);
t_dvec3	calc_sphere_normal(\
			t_sphere const *sphere, t_ray const *ray, t_dvec3 point);
t_dvec3	calc_plane_normal(t_plane const *plane, t_ray const *ray);
t_dvec3	calc_cylinder_normal(\
			t_cylinder const *cylinder, t_ray const *ray, t_dvec3 point);
t_dvec3	calc_circle_normal(t_circle const *circle, t_ray const *ray);

#endif
