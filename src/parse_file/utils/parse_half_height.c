/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_half_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/18 22:03:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_half_height(char const *element, double *half_height)
{
	double	height;

	if (!parse_double(element, &height))
		return (false);
	if (height <= 0.0)
	{
		print_error(ERROR_HEIGHT_RANGE);
		return (false);
	}
	*half_height = height / 2.0;
	if (*half_height == 0.0)
	{
		print_error(ERROR_HEIGHT_SMALL);
		return (false);
	}
	return (true);
}
