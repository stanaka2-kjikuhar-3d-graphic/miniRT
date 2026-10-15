/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directional_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:14:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 13:46:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "vector.h"

#include "../light_private.h"

void	set_directional_light(size_t id, t_vec3 dir)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->type = DIRECTIONAL_LIGHT;
	light->directional.dir = dir;
}
