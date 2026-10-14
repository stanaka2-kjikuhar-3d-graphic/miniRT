/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:38:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 05:52:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_private.h"

void	cleanup_object(void)
{
	cleanup_objects();
	cleanup_object_ids();
	cleanup_bvh_nodes();
	cleanup_bvh_leaves();
	cleanup_flat_list();
}
