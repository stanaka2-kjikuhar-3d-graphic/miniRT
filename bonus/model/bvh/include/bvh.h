/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:14:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 23:24:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "aabb.h"

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

bool				allocate_bvh(size_t bounded_aabb_count);
void				register_bvh_node(t_bvh_node const *node, size_t i);
t_bvh_node const	*get_bvh_node(size_t i);
void				cleanup_bvh(void);

#endif
