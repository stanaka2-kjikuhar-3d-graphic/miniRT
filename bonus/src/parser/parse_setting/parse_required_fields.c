/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_required_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:59:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:28:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_required_fields(t_required_field const *fields, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		set_error_line_str(fields[i].element);
		if (!fields[i].parse(fields[i].element, fields[i].value))
			return (false);
		++i;
	}
	return (true);
}
