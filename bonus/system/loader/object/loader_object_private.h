/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_object_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:40:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:09:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_OBJECT_PRIVATE_H
# define LOADER_OBJECT_PRIVATE_H

# include "object.h"
# include "loader_object.h"
# include "vector.h"
# include "material.h"
# include "range.h"

t_material			expand_to_material(t_material_input const *input);
t_material_input	calc_cap_disc_material(t_material const *material);
t_vec3				calc_cap_disc_normal(enum e_uv_type type, t_vec3 dir);
t_uv_layout			calc_cap_disc_uv_layout(\
						enum e_uv_type type, float aspect, t_range v_range);
float				calc_cap_disc_pattern_size(float radius);

#endif
