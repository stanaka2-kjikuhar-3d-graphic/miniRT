/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_setting_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 23:57:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:04:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_ctype.h"
#include "ft_string.h"

bool	is_setting_id(char const *id, char const *line)
{
	size_t	len;

	len = ft_strlen(id);
	while (ft_isspace(*line))
		++line;
	return (ft_strncmp(id, line, len) == 0 \
		&& (ft_isspace(line[len]) || line[len] == '\0'));
}
