/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_loader_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:40:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/15 23:14:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_LOADER_PRIVATE_H
# define OBJECT_LOADER_PRIVATE_H

# include <stdbool.h>

# include "object.h"
# include "object_loader.h"
# include "vector.h"
# include "matrix.h"

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
			t_material_option_input const *option);
void	set_option_from_material(t_material_option_input *option, \
			t_material const *material);
void	set_uv_checker(t_uv *uv, t_ivec2 checker_count);
t_mat3	calc_onb(t_vec3 n);
bool	build_primitive(t_primitive_frame const *frame, t_primitive *out);

#endif
