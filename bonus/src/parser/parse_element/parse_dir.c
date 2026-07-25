/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:45:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "ft_error.h"

#include "../parser_private.h"

bool	parse_dir(char const *element, void *value)
{
	t_vec3 *const	dir = (t_vec3 *)value;
	float			length;

	if (!parse_vec3(element, dir))
		return (false);
	length = vec3_length(*dir);
	if (length < 1.0f - NORMALIZED_EPSILON \
		|| 1.0f + NORMALIZED_EPSILON < length)
	{
		print_line_error(ERROR_DIR_NOT_NORMALIZED);
		return (false);
	}
	return (true);
}
