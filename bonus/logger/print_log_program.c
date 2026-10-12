/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_program.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:33:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 01:38:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "./logger_private.h"

bool	print_log_program(enum e_log_level level, char const *program_name)
{
	int const	fd = get_logging_fd(level);
	bool		result;

	result = print_log_level(fd, level, true);
	result = print_log_str("USAGE: ", fd, result);
	result = print_log_str(program_name, fd, result);
	result = print_log_str(" *.rt\n", fd, result);
	return (result);
}
