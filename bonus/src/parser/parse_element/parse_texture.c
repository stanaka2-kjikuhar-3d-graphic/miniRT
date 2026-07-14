/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:08:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/14 14:11:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_mlx.h"

bool	parse_texture(char const *element, void *value)
{
	t_texture **const	texture = (t_texture **)value;

	if (!create_texture((char *)element))
		return (false);
	*texture = get_texture((char *)element);
	return (true);
}
