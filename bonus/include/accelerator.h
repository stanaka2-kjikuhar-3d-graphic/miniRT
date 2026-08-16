/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:21:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 18:49:13 by stanaka2         ###   ########.fr       */
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
	float			centroid[3];
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
			t_aabb_leaf const	*start;
			size_t				count;
		}	leaves;
	};
}	t_bvh_node;

bool	build_accelerator(void);
void	cleanup_accelerator(void);

#endif
