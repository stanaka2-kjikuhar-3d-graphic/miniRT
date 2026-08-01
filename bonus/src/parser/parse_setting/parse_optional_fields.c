/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:53:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:01:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_string.h"

#include "color.h"
#include "object.h"

#include "ft_error.h"

#include "../parser_private.h"

static void						set_default_optional_fields(\
	t_optional_field const *fields);
static bool						parse_optional_field(\
	char const *element, t_optional_field const *fields, bool *used);
static enum e_optional_field	find_field_index(\
	char const *element, t_optional_field const *fields);
static void						print_unknown_option_error(\
	t_optional_field const *fields);

bool	parse_optional_fields(\
	char const **optional_elements, t_optional_field const *fields)
{
	bool	used[OPTIONAL_FIELD_COUNT];
	size_t	i;

	set_default_optional_fields(fields);
	ft_bzero(used, sizeof(used));
	i = 0;
	while (optional_elements[i] != NULL)
	{
		if (!parse_optional_field(optional_elements[i], fields, used))
			return (false);
		++i;
	}
	return (true);
}

static void	set_default_optional_fields(t_optional_field const *fields)
{
	enum e_optional_field	idx;

	idx = 0;
	while (idx < OPTIONAL_FIELD_COUNT)
	{
		if (fields[idx].value != NULL)
		{
			if (fields[idx].field_type == FIELD_IMAGE)
			{
				*(t_image **)fields[idx].value \
					= fields[idx].default_value.image;
			}
			else if (fields[idx].field_type == FIELD_COLOR)
				*(t_color *)fields[idx].value = fields[idx].default_value.color;
			else if (fields[idx].field_type == FIELD_BOOL)
				*(bool *)fields[idx].value = fields[idx].default_value.boolean;
			else if (fields[idx].field_type == FIELD_FLOAT)
				*(float *)fields[idx].value = fields[idx].default_value.number;
			else if (fields[idx].field_type == FIELD_INT)
				*(int *)fields[idx].value = fields[idx].default_value.integer;
		}
		++idx;
	}
}

static bool	parse_optional_field(\
	char const *element, t_optional_field const *fields, bool *used)
{
	char const				*equal;
	enum e_optional_field	idx;

	set_error_field("option", element);
	equal = ft_strchr(element, '=');
	if (equal == NULL)
	{
		print_field_error(ERROR_OPTION_FORMAT, HINT_OPTION_FORMAT);
		return (false);
	}
	idx = find_field_index(element, fields);
	if (idx == OPTIONAL_FIELD_COUNT)
	{
		print_unknown_option_error(fields);
		return (false);
	}
	set_error_field(fields[idx].key, equal + 1);
	if (used[idx])
	{
		print_field_error(ERROR_OPTION_DUP, NULL);
		return (false);
	}
	used[idx] = true;
	return (fields[idx].parse(equal + 1, fields[idx].value));
}

static enum e_optional_field	find_field_index(\
	char const *element, t_optional_field const *fields)
{
	enum e_optional_field	idx;

	idx = 0;
	while (idx < OPTIONAL_FIELD_COUNT)
	{
		if (fields[idx].value != NULL \
			&& is_option_id(fields[idx].key, element))
			return (idx);
		++idx;
	}
	return (OPTIONAL_FIELD_COUNT);
}

static void	print_unknown_option_error(t_optional_field const *fields)
{
	char const	*hints[OPTIONAL_FIELD_COUNT + 1];
	size_t		i;
	size_t		j;

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
	print_field_error_multi_hints(ERROR_OPTION_UNKNOWN, hints);
}
