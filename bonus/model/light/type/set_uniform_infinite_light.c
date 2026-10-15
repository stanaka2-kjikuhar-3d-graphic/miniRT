/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform_infinite_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:27:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 13:43:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "light.h"
#include "vector.h"

#include "../light_private.h"

void	set_uniform_infinite_light(size_t id)
{
	t_light	*light;

	light = get_mutable_light(id);
	light->type = UNIFORM_INFINITE_LIGHT;
}
