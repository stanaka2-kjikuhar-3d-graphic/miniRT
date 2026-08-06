/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:42:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:45:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_fov(char const *element, void *value)
{
	float *const	fov = (float *)value;

	if (!parse_float(element, fov))
		return (false);
	if (*fov <= 0.0f || 180.0f <= *fov)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_FOV_RANGE);
		return (false);
	}
	return (true);
}
