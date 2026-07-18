/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:38:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 14:28:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_angle(char const *element, void *value)
{
	float *const	angle = (float *)value;

	if (!parse_float(element, angle))
		return (false);
	if (*angle < 0.0f || 180.0f < *angle)
	{
		print_error(ERROR_ANGLE_RANGE);
		return (false);
	}
	return (true);
}
