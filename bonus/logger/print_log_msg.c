/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:20:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:45:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_msg(enum e_log_level level, char const *msg)
{
	int const	fd = get_logging_fd(level);
	bool		result;

	result = print_log_level(fd, level, true);
	result = print_log_str(msg, fd, result);
	result = print_log_str("\n", fd, result);
	return (result);
}
