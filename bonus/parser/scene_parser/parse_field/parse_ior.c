/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ior.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:15:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/30 21:36:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../scene_parser_private.h"

bool	parse_ior(char const *element, float *ior)
{
	if (!parse_float(element, ior))
		return (false);
	if (*ior < 0.0f)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_NON_NEGATIVE);
		return (false);
	}
	return (true);
}
