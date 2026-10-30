/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:08:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/20 00:09:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "texture.h"

bool	parse_texture(char const *element, t_texture_id *id)
{
	if (!create_texture((char *)element, id))
		return (false);
	return (true);
}
