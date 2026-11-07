/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_hint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 23:13:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:41:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_hint(enum e_log_level level, char const *hint)
{
	int const	fd = get_logging_fd(level);
	bool		result;

	result = true;
	if (hint != NULL)
	{
		result = print_log_str("USAGE: ", fd, result);
		result = print_log_str(hint, fd, result);
		result = print_log_str("\n", fd, result);
	}
	return (result);
}
