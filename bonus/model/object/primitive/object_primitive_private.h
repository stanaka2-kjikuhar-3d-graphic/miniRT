/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_primitive_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:02:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/10 20:50:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIMITIVE_PRIVATE_H
# define OBJECT_PRIMITIVE_PRIVATE_H

# include <stdbool.h>

# include "vector.h"
# include "matrix.h"
# include "primitive.h"

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

bool	build_primitive(t_primitive_frame const *frame, t_primitive *out);
t_mat3	mat3_build_onb(t_vec3 n);
void	set_primitive(size_t id, t_primitive const *primitive);

#endif
