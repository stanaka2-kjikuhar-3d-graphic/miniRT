/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:23:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 20:59:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_PRIVATE_H
# define FT_ERROR_PRIVATE_H

# include <stddef.h>
# include <unistd.h>

ssize_t		print_nbr(size_t nbr, int fd);
size_t		get_error_line_number(void);
char const	*get_error_line(void);
char const	*get_error_field(void);
char const	*get_error_token(void);

#endif
