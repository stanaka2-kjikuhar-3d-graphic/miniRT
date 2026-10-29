/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reflectivity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:14:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/20 00:07:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../parser_private.h"

bool	parse_reflectivity(char const *element, float *reflectivity)
{
	if (!parse_float(element, reflectivity))
		return (false);
	if (*reflectivity < 0.0f || 1.0f < *reflectivity)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_RATIO_RANGE);
		return (false);
	}
	return (true);
}
