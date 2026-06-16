/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 23:15:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "ray.h"

typedef struct s_object	t_object;

enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
};

typedef struct s_sphere
{
	t_dvec3	pos;
	double	radius;
}	t_sphere;

typedef struct s_plane
{
	t_dvec3	pos;
	t_dvec3	dir;
}	t_plane;

typedef struct s_cylinder
{
	t_dvec3	pos;
	t_dvec3	dir;
	double	radius;
	double	height;
}	t_cylinder;

typedef struct s_object
{
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	enum e_object_type	type;
	int					color;
}	t_object;

t_object const	*get_objects(void);
size_t			get_objects_count(void);
bool			allocate_objects(size_t	add_count);
bool			add_object(t_object *new);
void			cleanup_objects(void);
double			intersect_sphere(t_sphere const *sphere, t_ray const *ray);

#endif
