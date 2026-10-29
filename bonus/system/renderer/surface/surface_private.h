/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 21:53:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURFACE_PRIVATE_H
# define SURFACE_PRIVATE_H

# include "object.h"
# include "vector.h"
# include "matrix.h"
# include "range.h"
# include "primitive.h"
# include "ray.h"
# include "material.h"

t_vec2	calc_object_uv(t_object const *object, t_vec3 point);
t_color	calc_object_color(\
			t_object const *object, t_material const *material, t_vec2 uv);
t_vec3	calc_object_normal(\
			t_object const *object, t_ray const *ray, t_vec3 point);
t_mat3	calc_object_tbn(t_object const *object, t_vec3 point, t_vec3 normal);
t_vec3	calc_bump_mapping(t_object const *object, \
			t_material const *material, t_vec2 uv, t_mat3 const *tbn);
t_vec3	calc_normal_mapping(\
			t_material const *material, t_vec2 uv, t_mat3 const *tbn);
t_vec3	calc_primitive_normal(\
			t_primitive const *prim, t_ray const *ray, t_vec3 point);
t_vec2	calc_primitive_uv(t_primitive const *prim, t_vec3 point, \
			t_uv_info const *uv);
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type);
t_vec2	adjust_uv_range(t_vec2 uv, t_range u_range, t_range v_range);

#endif
