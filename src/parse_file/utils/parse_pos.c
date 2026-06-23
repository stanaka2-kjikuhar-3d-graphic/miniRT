/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:31:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 23:49:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "../parse_file_private.h"

bool	parse_pos(char const *element, t_vec3 *pos)
{
	if (!parse_vec3(element, pos))
		return (false);
	return (true);
}
