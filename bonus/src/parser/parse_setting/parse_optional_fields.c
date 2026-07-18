/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:53:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/11 21:26:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "ft_string.h"

#include "ft_error.h"

#include "../parser_private.h"

static t_optional_field const	*find_field_index(char const *optional_element, \
							t_optional_field const *fields, size_t count);
static bool						validate_option(bool format, \
							t_optional_field const *option, bool is_duplicate);

bool	parse_optional_fields(char const **optional_elements, \
			t_optional_field const *fields, size_t count)
{
	t_optional_field const	*option;
	char const				*equal;
	uint32_t				used;
	uint32_t				mask;
	size_t					i;

	used = 0;
	i = 0;
	while (optional_elements[i] != NULL)
	{
		equal = ft_strchr(optional_elements[i], '=');
		option = find_field_index(optional_elements[i], fields, count);
		if (option != NULL)
			mask = (uint32_t)1 << (option - fields);
		else
			mask = 0;
		if (!validate_option(equal != NULL, option, used & mask))
			return (false);
		used |= mask;
		if (!(option->parse(equal + 1, option->value)))
			return (false);
		++i;
	}
	return (true);
}

static t_optional_field const	*find_field_index(\
	char const *optional_element, t_optional_field const *fields, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (is_option_id(fields[i].key, optional_element))
			return (&(fields[i]));
		++i;
	}
	return (NULL);
}

/* ヒントがマテリアルだけになってしまっているので修正要 */
static bool	validate_option(\
	bool format, t_optional_field const *option, bool is_duplicate)
{
	if (!format)
	{
		print_error_hint(ERROR_OPTION_FORMAT, \
			HINT_MATERIAL_OPTION1 HINT_MATERIAL_OPTION2 HINT_MATERIAL_OPTION3);
		return (false);
	}
	if (option == NULL)
	{
		print_error_hint(ERROR_OPTION_UNKNOWN, \
			HINT_MATERIAL_OPTION1 HINT_MATERIAL_OPTION2 HINT_MATERIAL_OPTION3);
		return (false);
	}
	if (is_duplicate)
	{
		print_error(ERROR_OPTION_DUP);
		return (false);
	}
	return (true);
}
