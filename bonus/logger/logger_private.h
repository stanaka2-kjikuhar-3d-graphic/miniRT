/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:23:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:47:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_PRIVATE_H
# define LOGGER_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include <logger.h>

size_t		get_log_line_number(void);
char const	*get_log_line(void);
char const	*get_log_field(void);
char const	*get_log_token(void);
int			get_logging_fd(enum e_log_level level);
bool		print_log_level(int fd, enum e_log_level level, bool result);
bool		print_log_str(char const *s, int fd, bool result);
bool		print_log_nbr(size_t nbr, int fd, bool result);

#endif
