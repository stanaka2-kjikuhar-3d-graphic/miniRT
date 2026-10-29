/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 01:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/19 23:54:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_string.h"

#include "logger.h"

bool	parse_bool(char const *element, bool *boolean)
{
	if (ft_strcmp("true", element) == 0)
		*boolean = true;
	else if (ft_strcmp("false", element) == 0)
		*boolean = false;
	else
	{
		print_log_field(LOG_ERROR, ERROR_MUST_BE_BOOL);
		return (false);
	}
	return (true);
}
