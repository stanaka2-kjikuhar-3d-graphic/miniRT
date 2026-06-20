/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:37:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 13:25:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "ft_error.h"

#include "../parse_file_private.h"

bool	parse_dir(char const *element, t_dvec3 *dir)
{
	double	length;

	if (!parse_dvec3(element, dir))
		return (false);
	length = dvec3_length(*dir);
	if (length < 1.0 - 1e-3 || 1.0 + 1e-3 < length)
	{
		print_error(ERROR_DIR_NOT_NORMALIZED);
		return (false);
	}
	*dir = dvec3_normalize(*dir);
	return (true);
}
