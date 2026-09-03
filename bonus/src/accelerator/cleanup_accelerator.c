/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_accelerator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:45:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 18:49:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./accelerator_private.h"

void	cleanup_accelerator(void)
{
	cleanup_bvh();
	cleanup_aabb_leaves();
	cleanup_infinite_objects();
}
