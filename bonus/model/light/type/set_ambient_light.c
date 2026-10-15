/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:26:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 13:45:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "color.h"

#include "../light_private.h"

void	set_ambient_light(size_t id)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->type = AMBIENT_LIGHT;
}
