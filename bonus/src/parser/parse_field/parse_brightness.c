/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:27:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:45:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_brightness(char const *element, void *value)
{
	float *const	brightness = (float *)value;

	if (!parse_float(element, brightness))
		return (false);
	if (*brightness < 0.0f || 1.0f < *brightness)
	{
		print_line_error(ERROR_BRIGHTNESS_RANGE, NULL);
		return (false);
	}
	return (true);
}
