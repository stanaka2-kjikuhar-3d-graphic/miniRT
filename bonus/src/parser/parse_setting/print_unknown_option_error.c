/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown_option_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:53:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 19:03:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_error.h"

#include "../parser_private.h"

static void	build_option_multi_hints(\
	t_optional_field const *fields, char const **hints);

void	print_unknown_option_error(t_optional_field const *fields)
{
	char const	*hints[OPTIONAL_FIELD_COUNT + 1];

	build_option_multi_hints(fields, hints);
	print_field_error_multi_hints(ERROR_OPTION_UNKNOWN, hints);
}

static void	build_option_multi_hints(\
	t_optional_field const *fields, char const **hints)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		if (fields[i].value != NULL)
		{
			hints[j] = fields[i].format_msg;
			++j;
		}
		++i;
	}
	hints[j] = NULL;
}
