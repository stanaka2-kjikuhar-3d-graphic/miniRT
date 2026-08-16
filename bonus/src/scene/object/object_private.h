/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:53:04 by kjikuhar         ###   ########.fr       */
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

typedef struct s_quadric_coeffs
{
	float	a;
	float	b;
	float	c;
}	t_quadric_coeffs;

typedef struct s_primitive_frame
{
	enum e_primitive_type	type;
	t_mat3					basis;
	t_vec3					origin;
	t_vec3					scale;
	t_range					z_range;
}	t_primitive_frame;

typedef struct s_quadric_frame
{
	t_mat4	local_q;
	t_onb	onb;
	t_vec3	center;
	float	h_min;
	float	h_max;
}	t_quadric_frame;

bool	create_object(t_object const *object);
void	set_material_from_option(t_material *material, t_color albedo, \
			t_material_option const *option);
void	set_option_from_material(t_material_option *option, \
			t_material const *material);
void	set_uv_checker(t_uv *uv, t_ivec2 checker_count);
float	calc_sphere_intersection(t_sphere const *sphere, t_ray const *ray);
float	calc_plane_intersection(t_plane const *plane, t_ray const *ray);
float	calc_cylinder_intersection(\
			t_cylinder const *cylinder, t_ray const *ray);
float	calc_circle_intersection(t_circle const *circle, t_ray const *ray);
float	calc_cone_intersection(t_cone const *cone, t_ray const *ray);
float	calc_hyperboloid_intersection(\
			t_hyperboloid const *hyperboloid, t_ray const *ray);
float	calc_paraboloid_intersection(\
			t_paraboloid const *paraboloid, t_ray const *ray);
t_vec2	calc_sphere_uv(t_sphere const *sphere, t_vec3 point);
t_vec2	calc_plane_uv(t_plane const *plane, t_vec3 point, float pattern_size);
t_vec2	calc_cylinder_uv(t_cylinder const *cylinder, t_vec3 point);
t_vec2	calc_circle_uv(\
			t_circle const *circle, t_vec3 point, enum e_uv_type uv_type);
t_vec2	calc_cone_uv(t_cone const *cone, t_vec3 point);
t_vec2	calc_hyperboloid_uv(t_hyperboloid const *hyperboloid, t_vec3 point);
t_vec2	calc_paraboloid_uv(t_paraboloid const *paraboloid, t_vec3 point);
t_color	calc_sphere_color(t_sphere const *sphere, t_vec2 uv);
t_color	calc_plane_color(t_plane const *plane, t_vec2 uv);
t_vec3	calc_sphere_normal(\
			t_sphere const *sphere, t_ray const *ray, t_vec3 point);
t_vec3	calc_plane_normal(t_plane const *plane, t_ray const *ray);
t_vec3	calc_cylinder_normal(\
			t_cylinder const *cylinder, t_ray const *ray, t_vec3 point);
t_vec3	calc_circle_normal(t_circle const *circle, t_ray const *ray);
t_onb	calc_sphere_tbn(t_sphere const *sphere, t_vec3 normal);
t_onb	calc_plane_tbn(t_plane const *plane, t_vec3 normal);
t_onb	calc_cylinder_tbn(t_cylinder const *cylinder, t_vec3 normal);
t_onb	calc_circle_tbn(t_circle const *circle, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type);
t_vec3	calc_cone_normal(\
			t_cone const *cone, t_ray const *ray, t_vec3 point);
t_vec3	calc_hyperboloid_normal(\
			t_hyperboloid const *hyperboloid, t_ray const *ray, t_vec3 point);
t_vec3	calc_paraboloid_normal(\
			t_paraboloid const *paraboloid, t_ray const *ray, t_vec3 point);
void	calc_onb(t_vec3 n, t_vec3 *tangent, t_vec3 *bitangent);
t_mat3	basis_from_dir(t_vec3 dir);
bool	build_primitive(t_primitive_frame const *frame, t_primitive *out);
t_mat4	unit_quadric(enum e_primitive_type type);
float	calc_primitive_intersection(\
			t_primitive const *prim, t_ray const *ray);
float	solve_unit_form(t_primitive const *prim, t_ray const *local);
t_vec3	calc_primitive_normal(\
			t_primitive const *prim, t_ray const *ray, t_vec3 point);
t_vec2	calc_primitive_uv(t_primitive const *prim, t_vec3 point, \
			enum e_uv_type uv_type);
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type);
float	calc_planar_intersection(\
			t_primitive const *prim, t_ray const *local);
t_vec2	adjust_uv_range(t_vec2 uv, t_range u_range, t_range v_range);
t_mat4	calc_cone_local_q(float k);
void	cone_to_quadric(t_cone const *cone, t_quadric *out);
t_mat4	calc_paraboloid_local_q(float a);
void	paraboloid_to_quadric(\
			t_paraboloid const *paraboloid, t_quadric *out);
t_mat4	calc_hyperboloid_local_q(float a, float b, float c);
void	hyperboloid_to_quadric(\
			t_hyperboloid const *hyperboloid, t_quadric *out);
void	build_quadric(t_quadric_frame const *frame, t_quadric *out);

#endif
