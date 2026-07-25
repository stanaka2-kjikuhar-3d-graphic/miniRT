/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:57:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"
#include "ft_string.h"

#include "ft_error.h"

#include "./parser_private.h"

static bool		parse_line(char *line, size_t *count);
static bool		parse_setting(char const **elements, size_t *count);
static bool		validate_required_setting(size_t const *count);

static const t_setting_parser	g_setting_parsers[SETTING_ID_COUNT] = {\
	[ID_AMBIENT_LIGHT] \
		= {"A", ERROR_ID_NO_A, ERROR_ID_DUP_A, parse_ambient_light}, \
	[ID_CAMERA] = {"C", ERROR_ID_NO_C, ERROR_ID_DUP_C, parse_camera}, \
	[ID_POINT_LIGHT] = {"L", ERROR_ID_NO_L, NULL, parse_point_light}, \
	[ID_SPHERE] = {"sp", NULL, NULL, parse_sphere}, \
	[ID_PLANE] = {"pl", NULL, NULL, parse_plane}, \
	[ID_CYLINDER] = {"cy", NULL, NULL, parse_cylinder}, \
	[ID_CONE] = {"co", NULL, NULL, parse_cone}, \
	[ID_HYPERBOLOID] = {"hb", NULL, NULL, parse_hyperboloid}, \
	[ID_PARABOLOID] = {"pb", NULL, NULL, parse_paraboloid}, \
	[ID_SPOT_LIGHT] = {"sl", NULL, NULL, parse_spot_light} \
};

bool	parse_settings(t_list **line_list)
{
	char	*line;
	size_t	line_no;
	size_t	count[SETTING_ID_COUNT];

	line_no = 0;
	ft_bzero(count, sizeof(count));
	while (*line_list != NULL)
	{
		line = ft_lst_pop_front(line_list);
		set_error_line_no(++line_no);
		set_error_line_str(line);
		if (!is_blank_line(line) && !parse_line(line, count))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (validate_required_setting(count));
}

static bool	parse_line(char *line, size_t *count)
{
	char	**elements;

	elements = ft_split_set(line, " \f\r\t\v");
	if (elements == NULL)
	{
		print_errno();
		return (false);
	}
	if (!parse_setting((char const **)elements, count))
	{
		free_split(elements);
		return (false);
	}
	free_split(elements);
	return (true);
}

static bool	parse_setting(char const **elements, size_t *count)
{
	enum e_setting_index	idx;

	idx = 0;
	while (idx < SETTING_ID_COUNT)
	{
		if (is_setting_id(g_setting_parsers[idx].id, elements[0]))
			break ;
		++idx;
	}
	if (idx == SETTING_ID_COUNT)
	{
		print_line_error(ERROR_ID_UNKNOWN);
		return (false);
	}
	++count[idx];
	if (count[idx] > 1 && g_setting_parsers[idx].dup_err != NULL)
	{
		print_line_error(g_setting_parsers[idx].dup_err);
		return (false);
	}
	return (g_setting_parsers[idx].parse(elements));
}

static bool	validate_required_setting(size_t const *count)
{
	enum e_setting_index	idx;

	idx = 0;
	while (idx < SETTING_ID_COUNT)
	{
		if (count[idx] == 0 && g_setting_parsers[idx].missing_err != NULL)
		{
			print_error(g_setting_parsers[idx].missing_err);
			return (false);
		}
		++idx;
	}
	return (true);
}
