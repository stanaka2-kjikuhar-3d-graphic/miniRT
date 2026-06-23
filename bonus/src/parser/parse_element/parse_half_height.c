/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_half_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 00:20:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_half_height(char const *element, float *half_height)
{
	float	height;

	if (!parse_float(element, &height))
		return (false);
	if (height <= 0.0)
	{
		print_error(ERROR_HEIGHT_RANGE);
		return (false);
	}
	*half_height = height / 2.0f;
	if (*half_height == 0.0)
	{
		print_error(ERROR_HEIGHT_SMALL);
		return (false);
	}
	return (true);
}
