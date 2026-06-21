/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:48:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:53:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "view.h"

#include "./scene_private.h"

void	change_camera_pos(t_dvec3 pos)
{
	get_mutable_camera()->pos = pos;
}
