/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 16:17:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"

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
	size_t				id;
	enum e_object_type	type;
	int					color;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
}	t_object;

bool	allocate_objects(size_t	add_count);
bool	add_object(t_object *new);
void	cleanup_objects(void);

#endif
