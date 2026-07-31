/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 01:20:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_string.h"

#include "ft_error.h"

bool	parse_bool(char const *element, void *value)
{
	bool *const	boolean = (bool *)value;

	if (ft_strcmp("true", element) == 0)
		*boolean = true;
	else if (ft_strcmp("false", element) == 0)
		*boolean = false;
	else
	{
		print_line_error(ERROR_BOOL_VALUE, NULL);
		return (false);
	}
	return (true);
}
