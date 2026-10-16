/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:42:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:38:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../parser_private.h"

bool	parse_fov(char const *element, void *value)
{
	float *const	fov = (float *)value;

	if (!parse_float(element, fov))
		return (false);
	if (*fov <= 0.0f || 180.0f <= *fov)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_FOV_RANGE);
		return (false);
	}
	return (true);
}
