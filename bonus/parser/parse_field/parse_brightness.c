/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:27:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/19 23:55:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../parser_private.h"

bool	parse_brightness(char const *element, float *brightness)
{
	if (!parse_float(element, brightness))
		return (false);
	if (*brightness < 0.0f || 1.0f < *brightness)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_BRIGHTNESS_RANGE);
		return (false);
	}
	return (true);
}
