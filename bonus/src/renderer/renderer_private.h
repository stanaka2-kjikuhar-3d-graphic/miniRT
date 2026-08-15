/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_PRIVATE_H
# define RENDERER_PRIVATE_H

# include <stdbool.h>

# include "config.h"
# include "object.h"
# include "vector.h"
# include "color.h"
# include "aabb.h"

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
			struct s_bvh_node const	*left;
			struct s_bvh_node const	*right;
		}	branch;
		struct s_bvh_leaves
		{
			t_aabb_leaf const	*start;
			size_t				count;
		}	leaves;
	};
}	t_bvh_node;

bool	check_render_flag(void);
void	phong(t_ivec2 pixel);
void	put_color_to_window_image(t_ivec2 pixel, t_color color);

#endif
