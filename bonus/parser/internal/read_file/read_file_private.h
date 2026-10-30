/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:40:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:31:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_PRIVATE_H
# define READ_FILE_PRIVATE_H

# include <stddef.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_buf
{
	char	data[BUFFER_SIZE];
	char	*head;
	ssize_t	read_bytes;
	char	*newline;
}	t_buf;

typedef struct s_line
{
	char	*data;
	size_t	len;
}	t_line;

bool	read_next_line(int fd, char **next_line);

#endif
