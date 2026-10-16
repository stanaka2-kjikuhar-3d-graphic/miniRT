/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_aabb_info_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:13:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:07:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_AABB_INFO_PRIVATE_H
# define OBJECT_AABB_INFO_PRIVATE_H

# include <stddef.h>

# include "aabb.h"
# include "id.h"

void	set_aabb_info(t_id object_id, t_aabb_info const *aabb_info);
float	mul_extent(float a, float b);

#endif
