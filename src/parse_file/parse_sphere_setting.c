/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_setting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:17:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 16:34:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"
#include "./parse_file_private.h"

bool	parse_sphere_setting(char const **elements)
{
	size_t		count;
	t_object	object;

	count = count_split(elements);
	if (count != 4)
	{
		if (count < 4)
			print_error_hint(ERROR_SPHERE_FEW, HINT_SPHERE);
		else
			print_error_hint(ERROR_SPHERE_MANY, HINT_SPHERE);
		return (false);
	}
	object.type = OBJ_SPHERE;
	if (!parse_pos(elements[1], &(object.sphere.pos)) \
		|| !parse_radius(elements[2], &(object.sphere.radius)) \
		|| !parse_color(elements[3], &(object.color)))
	{
		return (false);
	}
	if (!add_object(&object))
		return (false);
	return (true);
}
