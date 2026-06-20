/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:53:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:05:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#include "ft_stdlib.h"
#include "ft_string.h"

#include "ft_error.h"

#include "./read_next_line_private.h"

static bool	read_file(int fd, t_buf *buf, t_line *line);
static bool	append_to_line(t_buf *buf, t_line *line);

/*
Description
Each call reads a line from the file descriptor and stores it in next_line.
If '\n' is present, the string stored in next_line will not include '\n'.
If EOF is reached, the remaining string will be stored in next_line.
The string stored in next_line will be null-terminated.
If an fd that has already reached EOF is passed, a NULL pointer will be stored
in next_line.
If a null byte ('\0') is found in the read bytes, or if the read() or
malloc() function fails, a NULL pointer will be stored in next_line.

Return Value
Returns true if the next_line was successfully stored, or if there is no line
at EOF.
Returns false if a null byte ('\0') is found in the read bytes, or if the
read() or malloc() function fails.
*/
bool	read_next_line(int fd, char **next_line)
{
	static t_buf	buf;
	t_line			line;

	ft_bzero(&line, sizeof(t_line));
	if (!read_file(fd, &buf, &line))
	{
		buf.read_bytes = 0;
		buf.used_bytes = 0;
		free(line.data);
		*next_line = NULL;
		return (false);
	}
	*next_line = line.data;
	return (true);
}

static bool	read_file(int fd, t_buf *buf, t_line *line)
{
	while (true)
	{
		if (buf->used_bytes == buf->read_bytes)
		{
			buf->used_bytes = 0;
			buf->read_bytes = read(fd, buf->data, BUFFER_SIZE);
			if (buf->read_bytes < 0)
			{
				print_errno();
				return (false);
			}
			else if (buf->read_bytes == 0)
				return (true);
			if (ft_memchr(buf->data, '\0', buf->read_bytes) != NULL)
			{
				print_error(ERROR_FILE_BINARY);
				return (false);
			}
		}
		if (!append_to_line(buf, line))
			return (false);
		if (buf->data[buf->used_bytes - 1] == '\n')
			return (true);
	}
}

static bool	append_to_line(t_buf *buf, t_line *line)
{
	char	*newline;
	size_t	appended_size;

	newline = ft_memchr(&(buf->data[buf->used_bytes]), \
							'\n', buf->read_bytes - buf->used_bytes);
	if (newline == NULL)
		appended_size = buf->read_bytes - buf->used_bytes;
	else
		appended_size = newline - &(buf->data[buf->used_bytes]);
	if (line->allocated_size == 0)
		line->allocated_size += sizeof("");
	line->allocated_size += appended_size;
	line->data = ft_reallocf(line->data, line->len, line->allocated_size);
	if (line->data == NULL)
	{
		print_errno();
		return (false);
	}
	ft_strlcpy(&(line->data[line->len]), &(buf->data[buf->used_bytes]), \
			appended_size + 1);
	line->len += appended_size;
	buf->used_bytes += appended_size;
	if (newline != NULL)
		++(buf->used_bytes);
	return (true);
}
