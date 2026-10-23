/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:51:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:41:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

#include "../parse_setting_private.h"

enum e_normal_type	get_normal_type(char const **optional_elements)
{
	enum e_normal_type	type;
	size_t				i;

	type = NORMAL_OBJECT;
	i = 0;
	while (optional_elements[i] != NULL)
	{
		if (is_option_id("bump_map", optional_elements[i]))
			type = BUMP_MAP;
		else if (is_option_id("normal_map", optional_elements[i]))
			type = NORMAL_MAP;
		++i;
	}
	return (type);
}
