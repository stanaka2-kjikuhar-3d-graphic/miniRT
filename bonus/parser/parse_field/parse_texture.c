/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:08:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:43:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "texture.h"

bool	parse_texture(char const *element, void *value)
{
	t_texture_id *const	texture_id = (t_id *)value;

	if (!create_texture((char *)element, texture_id))
		return (false);
	return (true);
}
