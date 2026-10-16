/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_level.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 23:58:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:10:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdio.h"

#include "logger.h"

bool	print_log_level(int fd, enum e_log_level level, bool result)
{
	char	*level_msg;

	if (level == LOG_INFO)
		level_msg = "Info";
	else if (level == LOG_WARN)
		level_msg = "Warning";
	else if (level == LOG_ERROR)
		level_msg = "Error";
	else
		level_msg = "INVALID_LOG_LEVEL";
	if (ft_putendl_fd_bytes(level_msg, fd) == -1)
		return (false);
	return (result);
}
