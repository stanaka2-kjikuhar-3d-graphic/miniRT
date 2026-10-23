/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 06:21:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:49:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SETTINGS_PRIVATE_H
# define PARSE_SETTINGS_PRIVATE_H

# include <stdbool.h>

# include "loader.h"

enum e_setting
{
	SETTING_AMBIENT_LIGHT,
	SETTING_CAMERA,
	SETTING_POINT_LIGHT,
	SETTING_SPOT_LIGHT,
	SETTING_DIRECTIONAL_LIGHT,
	SETTING_SPHERE,
	SETTING_PLANE,
	SETTING_CYLINDER,
	SETTING_CONE,
	SETTING_HYPERBOLOID,
	SETTING_PARABOLOID,
	SETTING_ID_COUNT
};

typedef struct s_setting_parser
{
	char const	*id;
	char const	*missing_err;
	char const	*dup_err;
	bool		(*parse)(char const **, t_scene_input *);
}	t_setting_parser;

bool	is_blank_line(char const *line);
bool	is_comment_line(char const *line);
bool	is_setting_id(char const *id, char const *line);
void	free_split(char **split);

#endif
