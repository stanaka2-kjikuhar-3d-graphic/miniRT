/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:27:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 23:49:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_brightness(char const *element, double *brightness)
{
	if (!parse_double(element, brightness))
		return (false);
	if (*brightness < 0.0 || 1.0 < *brightness)
	{
		print_error(ERROR_BRIGHTNESS_RANGE);
		return (false);
	}
	return (true);
}
