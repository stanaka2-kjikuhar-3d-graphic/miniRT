/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 02:33:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"
# include "ray.h"

# define INTENSITY 1.0

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
	t_dvec3	center;
	double	radius;
}	t_sphere;

typedef struct s_plane
{
	t_color	color;
	t_dvec3	pos;
	t_dvec3	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_color		color;
	t_dvec3		center;
	t_dvec3		dir;
	double		radius;
	double		half_height;
}	t_cylinder;

typedef struct s_circle
{
	t_color	color;
	t_dvec3	center;
	t_dvec3	normal;
	double	radius;
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

t_object const	*get_objects(void);
size_t			get_objects_count(void);
bool			allocate_objects(size_t	add_count);
bool			add_object(t_object *new);
void			cleanup_objects(void);
double			intersect(t_object const *object, t_ray const *ray);
t_dvec3			calc_normal(\
					t_object const *object, t_ray const *ray, t_dvec3 point);
t_color			get_object_color(t_object const *object);

#endif
