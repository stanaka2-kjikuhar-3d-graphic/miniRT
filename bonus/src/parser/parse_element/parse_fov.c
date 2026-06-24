/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:42:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 00:20:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_fov(char const *element, float *fov)
{
	if (!parse_float(element, fov))
		return (false);
	if (*fov <= 0.0 || 180.0 <= *fov)
	{
		print_error(ERROR_FOV_RANGE);
		return (false);
	}
	return (true);
}
