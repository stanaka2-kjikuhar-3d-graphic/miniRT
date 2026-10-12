/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_errno.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:20:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:46:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdbool.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_errno(enum e_log_level level)
{
	int const	error_number = errno;
	int const	fd = get_logging_fd(level);
	bool		result;

	result = print_log_level(fd, level, true);
	result = print_log_str(strerror(error_number), fd, result);
	result = print_log_str("\n", fd, result);
	return (result);
}
