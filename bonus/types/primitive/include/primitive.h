/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:21:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 07:19:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# include "matrix.h"
# include "range.h"

/*
each shape is a unit form in local space, placed by to_world.

    INFINITE_PLANE     z = 0, |x| <= half_size.x, |y| <= half_size.y
    UNIT_PLANE         z = 0, |x| <= 1, |y| <= 1
    UNIT_DISC          z = 0, x^2 + y^2 <= 1
    UNIT_SPHERE        x^2 + y^2 + z^2 = 1     z_range [-1, 1]
    UNIT_CYLINDER      x^2 + y^2       = 1     z_range [-1, 1]
    UNIT_CONE          x^2 + y^2 - z^2 = 0     z_range [ 0, 1]
    UNIT_HYPERBOLOID   x^2 + y^2 - z^2 = 1     z_range [-zc, zc]
    UNIT_PARABOLOID    x^2 + y^2 - z   = 0     z_range [ 0, 1]

  UNIT_HYPERBOLOID keeps zc per object: the unit form fixes both scales,
  so the z bound cannot be normalized to 1 as well.

  INFINITE_PLANE keeps half_size per object for the same reason: u_size
  and v_size may be given one at a time, and an infinite half cannot be
  folded into the scale. UNIT_PLANE is the case where both are finite,
  so there the bound is normalized to 1.
*/
enum e_primitive_type
{
	INFINITE_PLANE,
	UNIT_PLANE,
	UNIT_DISC,
	UNIT_SPHERE,
	UNIT_CYLINDER,
	UNIT_CONE,
	UNIT_HYPERBOLOID,
	UNIT_PARABOLOID,
};

typedef struct s_primitive
{
	enum e_primitive_type	type;
	// object_local to rebased_world
	t_mat4					to_world;
	// rebased_world to object_local
	t_mat4					to_local;
	union
	{
		t_range	z_range;
		t_vec2	half_size;
	};
}	t_primitive;

t_mat4	unit_quadric(enum e_primitive_type type);
bool	is_planar_primitive(enum e_primitive_type type);
bool	is_quadric_primitive(enum e_primitive_type type);

#endif
