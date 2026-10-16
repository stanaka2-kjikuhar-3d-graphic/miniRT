/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_logging_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 23:58:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:10:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "logger.h"

int	get_logging_fd(enum e_log_level level)
{
	if (level == LOG_INFO)
		return (STDOUT_FILENO);
	else if (level == LOG_WARN)
		return (STDERR_FILENO);
	else if (level == LOG_ERROR)
		return (STDERR_FILENO);
	return (STDERR_FILENO);
}
