/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_identifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 23:57:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 00:02:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_string.h"

bool	is_identifier(char const *id, char const *line)
{
	size_t	len;

	len = ft_strlen(id);
	return (ft_strncmp(id, line, len) == 0 \
		&& (line[len] == ' ' || line[len] == '\0'));
}
