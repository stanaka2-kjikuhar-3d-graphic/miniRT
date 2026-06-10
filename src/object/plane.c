/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:44:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 23:50:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"

static t_plane	g_plane;

t_plane const	*get_plane(void)
{
	return (&g_plane);
}

void	set_plane_pos(t_dvec3 pos)
{
	g_plane.pos = pos;
}

void	set_plane_dir(t_dvec3 dir)
{
	g_plane.dir = dir;
}

void	set_plane_color
