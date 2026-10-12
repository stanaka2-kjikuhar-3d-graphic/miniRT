/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 21:49:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURFACE_PRIVATE_H
# define SURFACE_PRIVATE_H

# include "object.h"
# include "vector.h"
# include "matrix.h"
# include "range.h"
# include "primitive.h"

t_vec3	calc_primitive_normal(\
			t_primitive const *prim, t_ray const *ray, t_vec3 point);
t_vec2	calc_primitive_uv(t_primitive const *prim, t_vec3 point, \
			t_uv const *uv);
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type);
t_vec2	adjust_uv_range(t_vec2 uv, t_range u_range, t_range v_range);

#endif
