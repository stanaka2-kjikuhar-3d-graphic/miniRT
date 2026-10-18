/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:14:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:21:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include <stdbool.h>
# include <stddef.h>

# include "aabb.h"
# include "object.h"

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

bool				allocate_bvh_nodes(size_t count);
void				register_bvh_node(t_bvh_node const *node, size_t i);
t_bvh_node const	*get_bvh_node(size_t i);
bool				allocate_bvh_leaves(size_t count);
void				register_bvh_leaf(size_t index, t_object_id id);
t_object const		*get_bvh_leaf(size_t i);
void				swap_bvh_leaves(size_t a, size_t b);
size_t				get_bvh_count(void);
void				set_bvh_count(size_t count);
void				clear_bvh_count(void);

#endif
