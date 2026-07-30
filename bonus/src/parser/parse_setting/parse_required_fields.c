/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_required_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:59:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 00:15:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_required_fields(char const **elements, \
			t_required_field const *fields, size_t count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (i < count)
	{
		set_error_field_and_token(fields[i].field, elements[j]);
		if (!fields[i].parse(elements[j], fields[i].value))
			return (false);
		++i;
		++j;
	}
	return (true);
}
