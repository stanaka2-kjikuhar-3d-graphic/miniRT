/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:09:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:54:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "light.h"
#include "dynamic_array.h"
#include "id.h"

#include "./light_private.h"

size_t	get_light_count(void)
{
	return (get_mutable_light_array()->used);
}

bool	create_light(t_id *id)
{
	t_light	light;

	if (!add_light_id(get_mutable_light_array()->used, &(light.id)) \
			|| !add_dynamic_array(get_mutable_light_array(), &light))
	{
		return (false);
	}
	*id = light.id;
	return (true);
}

void	cleanup_lights(void)
{
	cleanup_dynamic_array(get_mutable_light_array());
}
