/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:53:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/02 21:33:52 by stanaka2         ###   ########.fr       */
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

	line.data = NULL;
	line.len = 0;
	if (!read_file(fd, &buf, &line))
	{
		buf.read_bytes = 0;
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
		if (buf->read_bytes == 0)
		{
			buf->read_bytes = read(fd, buf->data, BUFFER_SIZE);
			if (buf->read_bytes < 0)
			{
				print_errno();
				return (false);
			}
			else if (buf->read_bytes == 0)
				return (true);
			buf->head = buf->data;
			if (ft_memchr(buf->head, '\0', buf->read_bytes) != NULL)
			{
				print_error(ERROR_FILE_BINARY);
				return (false);
			}
		}
		buf->newline = ft_memchr(buf->head, '\n', buf->read_bytes);
		if (!append_to_line(buf, line))
			return (false);
		if (buf->newline != NULL)
			return (true);
	}
}

static bool	append_to_line(t_buf *buf, t_line *line)
{
	size_t	appended_size;

	if (buf->newline == NULL)
		appended_size = buf->read_bytes;
	else
		appended_size = buf->newline - buf->head;
	line->data = ft_reallocf(line->data, sizeof(char) * line->len, \
					sizeof(char) * (line->len + appended_size + 1));
	if (line->data == NULL)
	{
		print_errno();
		return (false);
	}
	ft_memcpy(&(line->data[line->len]), buf->head, appended_size);
	line->len += appended_size;
	line->data[line->len] = (char)'\0';
	buf->head += appended_size;
	buf->read_bytes -= appended_size;
	if (buf->newline != NULL)
	{
		buf->head += 1;
		buf->read_bytes -= 1;
	}
	return (true);
}
