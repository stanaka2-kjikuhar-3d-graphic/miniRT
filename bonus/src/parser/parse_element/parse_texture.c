/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:08:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 13:00:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_mlx.h"

bool	parse_texture(char const *element, void *value)
{
	t_image **const	texture = (t_image **)value;

	if (!create_texture((char *)element))
		return (false);
	*texture = get_texture((char *)element);
	return (true);
}
