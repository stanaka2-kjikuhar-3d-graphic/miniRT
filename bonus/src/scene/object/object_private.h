/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:41:48 by kjikuhar         ###   ########.fr       */
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
#endif
