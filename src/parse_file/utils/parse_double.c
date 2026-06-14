/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:25:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 06:25:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_ctype.h"
#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_double(char const *element, double *value)
{
	if (!is_valid_floating_point_format(element))
	{
		print_error(ERROR_NUMBER_FORMAT);
		return (false);
	}
	*value = ft_strtod(element, (char **)&element);
	if (*element != '0')
	{
		print_error(ERROR_NUMBER_FORMAT);
		return (false);
	}
	return (true);
}
