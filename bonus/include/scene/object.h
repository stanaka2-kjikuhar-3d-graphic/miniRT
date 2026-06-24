/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 11:56:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"
# include "ray.h"

typedef struct s_object	t_object;

enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CIRCLE
};

typedef struct s_sphere
{
	t_color	color;
	t_vec3	center;
	float	radius;
}	t_sphere;

typedef struct s_plane
{
	t_color	color;
	t_vec3	pos;
	t_vec3	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_color		color;
	t_vec3		center;
	t_vec3		dir;
	float		radius;
	float		half_height;
}	t_cylinder;

typedef struct s_circle
{
	t_color	color;
	t_vec3	center;
	t_vec3	normal;
	float	radius;
}	t_circle;

typedef struct s_object
{
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_circle	circle;
		t_cylinder	cylinder;
	};
	enum e_object_type	type;
}	t_object;

bool			get_next_object(t_object const **object);
bool			add_object(t_object *object);
void			cleanup_objects(void);
float			intersect(t_object const *object, t_ray const *ray);
t_vec3			calc_normal(\
					t_object const *object, t_ray const *ray, t_vec3 point);
t_color			get_object_color(t_object const *object);

#endif
