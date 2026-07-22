/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_setting_ids.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:52:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 20:42:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_string.h"
#include "ft_lst.h"

#include "ft_error.h"

#include "./parser_private.h"

static bool	validate_invalid_id(char const *line);
static bool	validate_setting_count(t_setting_count count);

bool	validate_setting_ids(t_list *line_list)
{
	t_setting_count	count;
	char const		*line;

	ft_bzero(&count, sizeof(t_setting_count));
	while (line_list != NULL)
	{
		line = (char const *)(line_list->content);
		if (!validate_invalid_id(line))
			return (false);
		if (is_setting_id("A", line))
			++(count.ambient_light);
		else if (is_setting_id("L", line))
			++(count.point_light);
		else if (is_setting_id("C", line))
			++(count.camera);
		line_list = line_list->next;
	}
	if (!validate_setting_count(count))
		return (false);
	return (true);
}

static bool	validate_invalid_id(char const *line)
{
	if (is_setting_id("A", line) \
		|| is_setting_id("L", line) \
		|| is_setting_id("C", line) \
		|| is_setting_id("sl", line) \
		|| is_setting_id("sp", line) \
		|| is_setting_id("pl", line) \
		|| is_setting_id("cy", line) \
		|| is_setting_id("co", line) \
		|| is_setting_id("hb", line) \
		|| is_setting_id("pb", line))
	{
		return (true);
	}
	else
	{
		print_error(ERROR_ID_UNKNOWN);
		return (false);
	}
}

static bool	validate_setting_count(t_setting_count count)
{
	if (count.ambient_light == 0)
		print_error(ERROR_ID_NO_A);
	else if (count.point_light == 0)
		print_error(ERROR_ID_NO_L);
	else if (count.camera == 0)
		print_error(ERROR_ID_NO_C);
	else if (count.ambient_light > 1)
		print_error(ERROR_ID_DUP_A);
	else if (count.camera > 1)
		print_error(ERROR_ID_DUP_C);
	else
		return (true);
	return (false);
}
