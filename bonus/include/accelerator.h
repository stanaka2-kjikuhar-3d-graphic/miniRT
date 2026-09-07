/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:21:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/06 15:33:23 by stanaka2         ###   ########.fr       */
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

typedef struct s_bvh_node
{
	t_aabb	aabb;
	bool	has_leaf;
	union
	{
		struct s_bvh_branch
		{
			size_t	left;
			size_t	right;
		}	branch;
		struct s_bvh_leaves
		{
			size_t	start;
			size_t	count;
		}	leaves;
	};
}	t_bvh_node;

bool				build_accelerator(void);
void				cleanup_accelerator(void);
t_object const		*get_infinite_object(size_t i);
size_t				get_infinite_object_count(void);
t_bvh_node const	*get_bvh_node(size_t i);
t_aabb_leaf const	*get_aabb_leaf(size_t i);

#endif
