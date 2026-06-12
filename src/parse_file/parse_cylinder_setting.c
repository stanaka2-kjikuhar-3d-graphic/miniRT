/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_setting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 01:33:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"
#include "./parse_file_private.h"

bool	parse_cylinder_setting(char const **elements)
{
	size_t		count;
	t_object	object;

	count = count_splitted(elements);
	if (count != 6)
	{
		if (count < 6)
			print_error_hint(ERROR_CYLINDER_FEW, HINT_CYLINDER);
		else
			print_error_hint(ERROR_CYLINDER_MANY, HINT_CYLINDER);
		return (false);
	}
	object.type = OBJ_CYLINDER;
	if (!parse_pos(elements[1], &(object.cylinder.pos)) \
		|| !parse_dir(elements[2], &(object.cylinder.dir)) \
		|| !parse_diameter(elements[3], &(object.cylinder.diameter)) \
		|| !parse_height(elements[4], &(object.cylinder.height)) \
		|| !parse_color(elements[5], &(object.color)))
	{
		return (false);
	}
	if (!add_object(&object))
		return (false);
	return (true);
}
