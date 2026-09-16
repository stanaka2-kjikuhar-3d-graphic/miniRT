/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_world_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:53:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "camera.h"

static bool	rebase_camera(t_vec3 rebased_origin);

bool	rebase_world_space(t_vec3 rebased_origin)
{
	if (!rebase_camera(rebased_origin))
		return (false);
	return (true);
}

static bool	rebase_camera(t_vec3 rebased_origin)
{
	set_camera_pos(vec3_add(\
		vec3_sub(get_camera()->world_pos, rebased_origin), \
		get_camera()->world_move) \
	);
	return (true);
}
