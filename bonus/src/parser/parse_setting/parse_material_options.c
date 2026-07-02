/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_options.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:41:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 02:41:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static enum e_option_id	get_material_option_id(\
							char const *optional_element);
static bool				validate_material_option(\
							int *flag, enum e_option_id option_id, bool format);
static void				set_material_pattern(\
							t_material *material, enum e_option_id option_id);
static bool				parse_material_option(t_material *material, \
						enum e_option_id option_id, char const *option_value);

bool	parse_material_options(\
	char const **optional_elements, t_material *material)
{
	int					flag;
	size_t				i;
	char				*equal;
	enum e_option_id	option_id;

	flag = 0;
	i = 0;
	while (optional_elements[i] != NULL)
	{
		option_id = get_material_option_id(optional_elements[i]);
		equal = ft_strchr(optional_elements[i], '=');
		if (!validate_material_option(&flag, option_id, equal != NULL))
			return (false);
		set_material_pattern(material, option_id);
		if (!parse_material_option(material, option_id, equal + 1))
			return (false);
		++i;
	}
	return (true);
}

static enum e_option_id	get_material_option_id(\
	char const *optional_element)
{
	if (is_option_id("texture", optional_element))
		return (OPTION_TEXTURE);
	if (is_option_id("checker_color1", optional_element))
		return (OPTION_CHECKERBOARD_COLOR1);
	if (is_option_id("checker_color2", optional_element))
		return (OPTION_CHECKERBOARD_COLOR2);
	if (is_option_id("checker_size", optional_element))
		return (OPTION_CHECKERBOARD_SIZE);
	if (is_option_id("metalness", optional_element))
		return (OPTION_METALNESS);
	if (is_option_id("shininess", optional_element))
		return (OPTION_SHININESS);
	return (INVALID_OPTION_ID);
}

static bool	validate_material_option(\
	int *flag, enum e_option_id option_id, bool format)
{
	if (!format)
	{
		print_error_hint(ERROR_OPTION_FORMAT, \
			HINT_MATERIAL_OPTION1 HINT_MATERIAL_OPTION2 \
			HINT_MATERIAL_OPTION3 HINT_MATERIAL_OPTION4);
		return (false);
	}
	if (option_id == INVALID_OPTION_ID)
	{
		print_error_hint(ERROR_OPTION_UNKNOWN, \
			HINT_MATERIAL_OPTION1 HINT_MATERIAL_OPTION2 \
			HINT_MATERIAL_OPTION3 HINT_MATERIAL_OPTION4);
		return (false);
	}
	if (*flag & (1 << option_id))
	{
		print_error(ERROR_OPTION_DUP);
		return (false);
	}
	*flag |= (1 << option_id);
	return (true);
}

static void	set_material_pattern(\
	t_material *material, enum e_option_id option_id)
{
	if (option_id == OPTION_TEXTURE)
		material->pattern_type = PATTERN_TEXTURE;
	else if (option_id == OPTION_CHECKERBOARD_COLOR1 \
		|| option_id == OPTION_CHECKERBOARD_COLOR2 \
		|| option_id == OPTION_CHECKERBOARD_SIZE)
	{
		material->pattern_type = PATTERN_CHECKERBOARD;
	}
}

static bool	parse_material_option(t_material *material, \
	enum e_option_id option_id, char const *option_value)
{
	if (option_id == OPTION_TEXTURE)
		return (parse_texture(option_value, &(material->texture)));
	else if (option_id == OPTION_CHECKERBOARD_COLOR1)
		return (parse_color(option_value, &(material->checkerboard.color1)));
	else if (option_id == OPTION_CHECKERBOARD_COLOR2)
		return (parse_color(option_value, &(material->checkerboard.color2)));
	else if (option_id == OPTION_CHECKERBOARD_SIZE)
		return (parse_size(option_value, &(material->checkerboard.size)));
	else if (option_id == OPTION_METALNESS)
		return (parse_metalness(option_value, &(material->metalness)));
	else if (option_id == OPTION_SHININESS)
		return (parse_shininess(option_value, &(material->shininess)));
	return (false);
}
