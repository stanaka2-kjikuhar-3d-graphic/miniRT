/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coordinate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:31:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/22 23:23:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "../parser_private.h"

bool	parse_coordinate(char const *element, t_vec3 *coordinate)
{
	if (!parse_vec3(element, coordinate))
		return (false);
	return (true);
}
