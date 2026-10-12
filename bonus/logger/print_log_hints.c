/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_hints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 00:06:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:46:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "./logger_private.h"

bool	print_log_hints(enum e_log_level level, char const **multi_hints)
{
	int const	fd = get_logging_fd(level);
	bool		result;
	size_t		i;

	result = true;
	if (multi_hints != NULL && multi_hints[0] != NULL)
	{
		result = print_log_str("USAGE:", fd, result);
		i = 0;
		while (multi_hints[i] != NULL)
		{
			result = print_log_str(" ", fd, result);
			result = print_log_str(multi_hints[i], fd, result);
			++i;
		}
		result = print_log_str("\n", fd, result);
	}
	return (result);
}
