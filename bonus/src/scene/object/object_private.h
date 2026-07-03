/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 19:41:46 by stanaka2         ###   ########.fr       */
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
float	calc_sphere_intersection(t_sphere const *sphere, t_ray const *ray);
float	calc_plane_intersection(t_plane const *plane, t_ray const *ray);
float	calc_cylinder_intersection(t_cylinder const *cylinder, t_ray const *ray);
float	calc_circle_intersection(t_circle const *circle, t_ray const *ray);
t_vec2	calc_plane_uv(t_plane const *plane, t_vec3 point);
t_color	calc_plane_color(t_plane const *plane, t_vec2 uv);
t_vec3	calc_sphere_normal(\
			t_sphere const *sphere, t_ray const *ray, t_vec3 point);
t_vec3	calc_plane_normal(t_plane const *plane, t_ray const *ray);
t_vec3	calc_cylinder_normal(\
			t_cylinder const *cylinder, t_ray const *ray, t_vec3 point);
t_vec3	calc_circle_normal(t_circle const *circle, t_ray const *ray);
void	compute_onb(t_vec3 n, t_vec3 *tangent, t_vec3 *bitangent);

#endif
