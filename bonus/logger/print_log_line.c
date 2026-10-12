/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:55:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:45:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_line(enum e_log_level level, char const *msg)
{
	int const	fd = get_logging_fd(level);
	bool		result;

	result = print_log_level(fd, level, true);
	result = print_log_str("line ", fd, result);
	result = print_log_nbr(get_log_line_number(), fd, result);
	result = print_log_str(": ", fd, result);
	result = print_log_str(get_log_line(), fd, result);
	result = print_log_str("\n", fd, result);
	result = print_log_str(msg, fd, result);
	result = print_log_str("\n", fd, result);
	return (result);
}
