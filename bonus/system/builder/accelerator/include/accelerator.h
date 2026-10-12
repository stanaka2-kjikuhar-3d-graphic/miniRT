
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:21:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 23:18:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCELERATOR_H
# define ACCELERATOR_H

# include <stdbool.h>
# include <stddef.h>

# include "aabb.h"
# include "object.h"

typedef struct s_aabb_leaf
{
	t_aabb			aabb;
	t_vec3			centroid;
	t_object const	*object;
}	t_aabb_leaf;

bool				build_accelerator(void);
t_object const		*get_infinite_object(size_t i);
size_t				get_infinite_object_count(void);
t_aabb_leaf const	*get_aabb_leaf(size_t i);
void				cleanup_infinite_objects(void);
void				cleanup_aabb_leaves(void);

#endif
