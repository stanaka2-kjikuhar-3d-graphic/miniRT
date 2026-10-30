/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paraboloid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 07:42:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "loader.h"
#include "loader_object.h"

#include "./loader_object_private.h"

bool	load_paraboloid(t_input const *input)
{
	t_object_id					id;
	t_paraboloid_input const	*paraboloid;
	t_material					material;

	if (!create_object(&id))
		return (false);
	paraboloid = &(input->paraboloid);
	material = expand_to_material(&(paraboloid->material));
	if (!set_paraboloid_primitive(id, &(paraboloid->paraboloid)))
		return (false);
	if (!set_object_material(id, &material))
		return (false);
	set_paraboloid_uv_layout(id, UV_DEFAULT, &(paraboloid->paraboloid));
	set_uv_checker(id, paraboloid->checker_count);
	set_paraboloid_aabb_info(id, get_primitive(id));
	return (true);
}
