/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reflectivity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:14:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/15 22:07:03 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_reflectivity(char const *element, void *value)
{
	float *const	reflectivity = (float *)value;

	if (!parse_float(element, reflectivity))
		return (false);
	if (*reflectivity < 0.0f || 1.0f < *reflectivity)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_RATIO_RANGE);
		return (false);
	}
	return (true);
}
