/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:53:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:07:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_string.h"

#include "logger.h"

#include "../parse_setting_private.h"

static bool						parse_optional_field(char const *element, \
									t_optional_field const *fields, bool *used);
static enum e_optional_field	find_field_index(char const *element, \
									t_optional_field const *fields);
static void						print_option_hints(\
									t_optional_field const *fields);

bool	parse_optional_fields(\
	char const **optional_elements, t_optional_field *fields)
{
	bool	used[OPTIONAL_FIELD_COUNT];
	size_t	i;

	set_default_values(fields);
	ft_bzero(used, sizeof(used));
	i = 0;
	while (optional_elements[i] != NULL)
	{
		set_log_field("option", optional_elements[i]);
		if (!parse_optional_field(optional_elements[i], fields, used))
			return (false);
		++i;
	}
	return (true);
}

static bool	parse_optional_field(\
	char const *element, t_optional_field const *fields, bool *used)
{
	char const *const		equal = ft_strchr(element, '=');
	enum e_optional_field	i;

	if (equal == NULL)
	{
		print_log_field(LOG_ERROR, ERROR_OPTION_FORMAT);
		print_log_hint(LOG_ERROR, HINT_OPTION_FORMAT);
		return (false);
	}
	i = find_field_index(element, fields);
	if (i == OPTIONAL_FIELD_COUNT)
	{
		print_log_field(LOG_ERROR, ERROR_OPTION_UNKNOWN);
		print_option_hints(fields);
		return (false);
	}
	if (used[i])
	{
		print_log_field(LOG_ERROR, ERROR_OPTION_DUP);
		return (false);
	}
	used[i] = true;
	set_log_field(fields[i].key, equal + 1);
	return (parse_field(fields[i].field_type, \
				fields[i].parser, equal + 1, fields[i].value));
}

static enum e_optional_field	find_field_index(\
	char const *element, t_optional_field const *fields)
{
	enum e_optional_field	i;

	i = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		if (fields[i].is_set && is_option_id(fields[i].key, element))
			return (i);
		++i;
	}
	return (OPTIONAL_FIELD_COUNT);
}

static void	print_option_hints(t_optional_field const *fields)
{
	char const	*hints[OPTIONAL_FIELD_COUNT + 1];
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		if (fields[i].is_set)
		{
			hints[j] = fields[i].format_msg;
			++j;
		}
		++i;
	}
	hints[j] = NULL;
	print_log_hints(LOG_ERROR, hints);
}
