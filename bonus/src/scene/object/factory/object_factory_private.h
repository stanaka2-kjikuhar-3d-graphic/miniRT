/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_factory_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:59:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 17:05:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FACTORY_PRIVATE_H
# define OBJECT_FACTORY_PRIVATE_H

#include <stdbool.h>

#include "object.h"
#include "object_factory.h"
#include "vector.h"
#include "matrix.h"

typedef struct s_primitive_frame
{
	enum e_primitive_type	type;
	t_mat3					basis;
	t_vec3					origin;
	t_vec3					scale;
	union
	{
		t_range				z_range;
		t_vec2				half_size;
	};
}	t_primitive_frame;

void	set_material_from_option(t_material *material, t_color albedo, \
			t_input_material_option const *option);
void	set_option_from_material(t_input_material_option *option, \
			t_material const *material);
void	set_uv_checker(t_uv *uv, t_ivec2 checker_count);
t_mat3	calc_onb(t_vec3 n);
bool	build_primitive(t_primitive_frame const *frame, t_primitive *out);

#endif
