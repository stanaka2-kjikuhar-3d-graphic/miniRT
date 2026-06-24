/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:40:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/09 21:43:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_NEXT_LINE_PRIVATE_H
# define READ_NEXT_LINE_PRIVATE_H

# include <stddef.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_buf
{
	char	data[BUFFER_SIZE];
	ssize_t	read_bytes;
	ssize_t	used_bytes;
}	t_buf;

typedef struct s_line
{
	char	*data;
	size_t	len;
	size_t	allocated_size;
}	t_line;

#endif
