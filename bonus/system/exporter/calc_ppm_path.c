/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ppm_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_string.h"

#include "./exporter_private.h"

static size_t	calc_stem_len(char const *name);

// シーンのディレクトリを落とし、拡張子を .ppm に替えたパスを返す
char	*calc_ppm_path(char const *scene_path)
{
	char const	*name;
	size_t		stem_len;
	char		*path;

	name = ft_strrchr(scene_path, '/');
	if (name != NULL)
		++name;
	else
		name = scene_path;
	stem_len = calc_stem_len(name);
	path = malloc(stem_len + ft_strlen(PPM_EXTENSION) + 1);
	if (path == NULL)
		return (NULL);
	ft_memcpy(path, name, stem_len);
	ft_strlcpy(path + stem_len, PPM_EXTENSION, ft_strlen(PPM_EXTENSION) + 1);
	return (path);
}

static size_t	calc_stem_len(char const *name)
{
	size_t const	len = ft_strlen(name);
	size_t const	ext_len = ft_strlen(RT_EXTENSION);

	if (len <= ext_len || ft_strcmp(name + len - ext_len, RT_EXTENSION) != 0)
		return (len);
	return (len - ext_len);
}
