/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform_infinite_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:27:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:05:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "vector.h"
#include "id.h"

#include "../light_private.h"

void	set_uniform_infinite_light(t_id light_id)
{
	t_light	*light;

	light = get_mutable_light(light_id);
	light->type = UNIFORM_INFINITE_LIGHT;
}
