/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 03:00:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"
#include "ft_string.h"

#include "ft_error.h"

#include "./parser_private.h"

static bool		parse_line(char *line, bool *used);
static bool		parse_setting(char const **elements, bool *used);
static bool		validate_required_setting(bool const *used);

static const t_setting_parser	g_setting_parsers[SETTING_ID_COUNT] = {\
	[SETTING_AMBIENT_LIGHT] \
		= {"A", ERROR_ID_NO_A, ERROR_ID_DUP_A, parse_ambient_light}, \
	[SETTING_CAMERA] \
		= {"C", ERROR_ID_NO_C, ERROR_ID_DUP_C, parse_camera}, \
	[SETTING_POINT_LIGHT] = {"L", ERROR_ID_NO_L, NULL, parse_point_light}, \
	[SETTING_SPHERE] = {"sp", NULL, NULL, parse_sphere}, \
	[SETTING_PLANE] = {"pl", NULL, NULL, parse_plane}, \
	[SETTING_CYLINDER] = {"cy", NULL, NULL, parse_cylinder}, \
	[SETTING_CONE] = {"co", NULL, NULL, parse_cone}, \
	[SETTING_HYPERBOLOID] = {"hb", NULL, NULL, parse_hyperboloid}, \
	[SETTING_PARABOLOID] = {"pb", NULL, NULL, parse_paraboloid}, \
	[SETTING_SPOT_LIGHT] = {"sl", NULL, NULL, parse_spot_light} \
};

bool	parse_settings(t_list **line_list)
{
	char	*line;
	size_t	line_number;
	bool	used[SETTING_ID_COUNT];

	line_number = 0;
	ft_bzero(used, sizeof(used));
	while (*line_list != NULL)
	{
		line = ft_lst_pop_front(line_list);
		set_error_line_number_and_line(++line_number, line);
		if (!is_blank_line(line) && !is_comment_line(line) \
			&& !parse_line(line, used))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (validate_required_setting(used));
}

static bool	parse_line(char *line, bool *used)
{
	char	**elements;

	elements = ft_split_set(line, " \f\r\t\v");
	if (elements == NULL)
	{
		print_errno();
		return (false);
	}
	if (!parse_setting((char const **)elements, used))
	{
		free_split(elements);
		return (false);
	}
	free_split(elements);
	return (true);
}

static bool	parse_setting(char const **elements, bool *used)
{
	enum e_setting	idx;

	idx = 0;
	while (idx < SETTING_ID_COUNT)
	{
		if (is_setting_id(g_setting_parsers[idx].id, elements[0]))
			break ;
		++idx;
	}
	if (idx == SETTING_ID_COUNT)
	{
		print_line_error(ERROR_ID_UNKNOWN, NULL);
		return (false);
	}
	if (used[idx] == true \
		&& g_setting_parsers[idx].dup_err != NULL)
	{
		print_line_error(g_setting_parsers[idx].dup_err, NULL);
		return (false);
	}
	used[idx] = true;
	return (g_setting_parsers[idx].parse(elements));
}

static bool	validate_required_setting(bool const *used)
{
	enum e_setting	idx;

	idx = 0;
	while (idx < SETTING_ID_COUNT)
	{
		if (used[idx] == false \
			&& g_setting_parsers[idx].missing_err != NULL)
		{
			print_error(g_setting_parsers[idx].missing_err);
			return (false);
		}
		++idx;
	}
	return (true);
}
