/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_setting_ids.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:52:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:30:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_string.h"
#include "ft_lst.h"

#include "ft_error.h"

#include "./parser_private.h"

static bool	validate_invalid_id(char const *line);
static bool	validate_duplicated_id(int flags, char const *line);
static bool	validate_required_id(int flags);

bool	validate_setting_ids(t_list *line_list)
{
	int			flags;
	char const	*line;

	flags = 0;
	while (line_list != NULL)
	{
		line = (char const *)(line_list->content);
		if (!validate_invalid_id(line))
			return (false);
		if (!validate_duplicated_id(flags, line))
			return (false);
		if (is_identifier("A", line))
			flags |= (1 << SETTING_AMBIENT_LIGHT);
		else if (is_identifier("L", line))
			flags |= (1 << SETTING_LIGHT);
		else if (is_identifier("C", line))
			flags |= (1 << SETTING_CAMERA);
		line_list = line_list->next;
	}
	if (!validate_required_id(flags))
		return (false);
	return (true);
}

static bool	validate_invalid_id(char const *line)
{
	if (is_identifier("A", line) \
		|| is_identifier("L", line) \
		|| is_identifier("C", line) \
		|| is_identifier("sl", line) \
		|| is_identifier("sp", line) \
		|| is_identifier("pl", line) \
		|| is_identifier("cy", line))
	{
		return (true);
	}
	else
	{
		print_error(ERROR_ID_UNKNOWN);
		return (false);
	}
}

static bool	validate_duplicated_id(int flags, char const *line)
{
	enum e_setting_id	setting_id;

	if (is_identifier("A", line))
		setting_id = SETTING_AMBIENT_LIGHT;
	else if (is_identifier("C", line))
		setting_id = SETTING_CAMERA;
	else
		return (true);
	if (flags & (1 << setting_id))
	{
		if (setting_id == SETTING_AMBIENT_LIGHT)
			print_error(ERROR_ID_DUP_A);
		else if (setting_id == SETTING_CAMERA)
			print_error(ERROR_ID_DUP_C);
		return (false);
	}
	return (true);
}

static bool	validate_required_id(int flags)
{
	if ((flags & (1 << SETTING_AMBIENT_LIGHT)) == 0)
	{
		print_error(ERROR_ID_NO_A);
		return (false);
	}
	else if ((flags & (1 << SETTING_LIGHT)) == 0)
	{
		print_error(ERROR_ID_NO_L);
		return (false);
	}
	else if ((flags & (1 << SETTING_CAMERA)) == 0)
	{
		print_error(ERROR_ID_NO_C);
		return (false);
	}
	return (true);
}
