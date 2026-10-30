/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_uniform_infinite_light.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:27:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:49:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "light.h"
#include "loader.h"
#include "loader_light.h"

bool	load_uniform_infinite_light(t_input const *input)
{
	t_light_id								id;
	t_uniform_infinite_light_input const	*uniform_infinite_light;

	if (!create_light(&id))
		return (false);
	uniform_infinite_light = &(input->uniform_infinite_light);
	set_uniform_infinite_light(id);
	set_uniform_infinite_light_radiance(id, \
		uniform_infinite_light->color, uniform_infinite_light->brightness);
	return (true);
}
