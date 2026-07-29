/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 16:22:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
#include <unicode/utypes.h>
#include <math.h>
#include <stdbool.h>

#include "ft_string.h"
#include "ft_stdio.h"

#include "vector.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	build_normalized_hint(t_vec3 dir, char *hint);

bool	parse_dir(char const *element, void *value)
{
	t_vec3 *const	dir = (t_vec3 *)value;
	float			length;
	char			hint[64];

	if (!parse_vec3(element, dir))
		return (false);
	length = vec3_length(*dir);
	if (length < 1.0f - NORMALIZED_EPSILON \
		|| 1.0f + NORMALIZED_EPSILON < length)
	{
		if (build_normalized_hint(*dir, hint))
			print_line_error(ERROR_DIR_NOT_NORMALIZED, hint);
		else
			print_line_error(ERROR_DIR_NOT_NORMALIZED, NULL);
		return (false);
	}
	return (true);
}

static bool	build_normalized_hint(t_vec3 dir, char *hint)
{
	float	max_abs;

	if (isinf(dir.x))
		dir.x = FLT_MAX * copysignf(1.0f, dir.x);
	if (isinf(dir.y))
		dir.y = FLT_MAX * copysignf(1.0f, dir.y);
	if (isinf(dir.z))
		dir.z = FLT_MAX * copysignf(1.0f, dir.z);
	max_abs = fmaxf(fabsf(dir.x), fmaxf(fabsf(dir.y), fabsf(dir.z)));
	if (max_abs == 0.0f)
	{
		ft_strcpy(hint, "0.577350,0.577350,0.577350");
		return (true);
	}
	dir.x /= max_abs;
	dir.y /= max_abs;
	dir.z /= max_abs;
	dir = vec3_normalize(dir);
	return (ft_sprintf(hint, "%.6f,%.6f,%.6f", dir.x, dir.y, dir.z) >= 0);
}
