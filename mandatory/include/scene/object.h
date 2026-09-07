/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:40:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"
# include "ray.h"
# include "ft_mlx.h"
# include "matrix.h"
# include "range.h"
# include "aabb.h"

/*
each shape is a unit form in local space, placed by to_world.

    INFINITE_PLANE     z = 0, |x| <= half_size.x, |y| <= half_size.y
    UNIT_DISC          z = 0, x^2 + y^2 <= 1
    UNIT_SPHERE        x^2 + y^2 + z^2 = 1     z_range [-1, 1]
    UNIT_CYLINDER      x^2 + y^2       = 1     z_range [-1, 1]
*/
enum e_primitive_type
{
	INFINITE_PLANE,
	UNIT_DISC,
	UNIT_SPHERE,
	UNIT_CYLINDER,
};

typedef struct s_primitive
{
	enum e_primitive_type	type;
	t_mat4					to_world;
	t_mat4					to_local;
	t_range					z_range;
}	t_primitive;

typedef struct s_object
{
	t_color		albedo;
	t_primitive	primitive;
	t_aabb_info	aabb_info;
}	t_object;

// input
typedef struct s_input_sphere
{
	t_vec3	center;
	float	radius;
	t_color	albedo;
}	t_input_sphere;

typedef struct s_input_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_color	albedo;
}	t_input_plane;

typedef struct s_input_cylinder
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	half_height;
	t_color	albedo;
}	t_input_cylinder;

typedef struct s_input_circle
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	t_color	albedo;
}	t_input_circle;

bool			create_sphere(t_input_sphere const *input);
bool			create_plane(t_input_plane const *input);
bool			create_cylinder(t_input_cylinder const *input);
bool			create_circle(t_input_circle const *input);
bool			get_next_object(t_object const **object);
t_object const	*get_object(size_t i);
size_t			get_object_count(void);
void			cleanup_objects(void);
float			calc_object_intersection(\
					t_object const *object, t_ray const *ray);
float			calc_aabb_intersection(t_aabb const *aabb, t_ray const *ray);
t_color			calc_object_color(t_object const *object);
t_vec3			calc_object_normal(\
					t_object const *object, t_ray const *ray, t_vec3 point);

#endif
