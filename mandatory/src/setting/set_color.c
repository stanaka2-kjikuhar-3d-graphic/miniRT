/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:59:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 02:46:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_color(t_color *color, char *data);
static bool	parse_color_value(int *color_value, char **data);

bool	set_floor_color(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_FLOOR_COLOR)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_FLOOR_COLOR;
	return (parse_color(&(setting->floor_color), data));
}

bool	set_ceiling_color(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_CEILING_COLOR)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_CEILING_COLOR;
	return (parse_color(&(setting->ceiling_color), data));
}

static bool	parse_color(t_color *color, char *data)
{
	if (!parse_color_value(&(color->r), &data))
		return (false);
	if (*(data++) != ',')
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	if (!parse_color_value(&(color->g), &data))
		return (false);
	if (*(data++) != ',')
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	if (!parse_color_value(&(color->b), &data))
		return (false);
	if (*data != '\0')
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	color->rgb = ((color->r << 16) | (color->g << 8) | color->b);
	color->alpha = 1.0;
	return (true);
}

static bool	parse_color_value(int *color_value, char **data)
{
	if (!ft_isdigit(**data))
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	*color_value = 0;
	if ((*data)[0] == '0' && ft_isdigit((*data)[1]))
	{
		print_error(ERROR_COLOR_LEADING_ZERO);
		return (false);
	}
	while (ft_isdigit(**data))
	{
		*color_value = *color_value * 10 + (**data - '0');
		if (*color_value > 255)
		{
			print_error(ERROR_COLOR_RANGE);
			return (false);
		}
		(*data)++;
	}
	return (true);
}
