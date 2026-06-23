/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:38:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parse_file_private.h"

bool	parse_angle(char const *element, float *angle)
{
	if (!parse_float(element, angle))
		return (false);
	if (*angle < 0.0 || 180.0 < *angle)
	{
		print_error(ERROR_ANGLE_RANGE);
		return (false);
	}
	return (true);
}
