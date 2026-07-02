/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:12:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 03:27:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_size(char const *element, float *size)
{
	if (!parse_float(element, size))
		return (false);
	if (*size <= 0.0f)
	{
		print_error(ERROR_SIZE_RANGE);
		return (false);
	}
	return (true);
}
