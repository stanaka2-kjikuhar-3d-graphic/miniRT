/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:33:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:05:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_file(\
	enum e_log_level level, char const *path, char const *msg)
{
	int const	fd = get_logging_fd(level);
	bool		result;

	result = print_log_level(fd, level, true);
	if (path != NULL && *path != '\0')
	{
		result = print_log_str(path, fd, result);
		result = print_log_str("\n", fd, result);
	}
	result = print_log_str(msg, fd, result);
	result = print_log_str("\n", fd, result);
	return (result);
}
