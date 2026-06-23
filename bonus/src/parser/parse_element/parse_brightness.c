/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:27:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 00:20:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_brightness(char const *element, float *brightness)
{
	if (!parse_float(element, brightness))
		return (false);
	if (*brightness < 0.0 || 1.0 < *brightness)
	{
		print_error(ERROR_BRIGHTNESS_RANGE);
		return (false);
	}
	return (true);
}
