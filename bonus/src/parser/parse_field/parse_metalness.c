/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metalness.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:12:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:46:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_string.h"

#include "ft_error.h"

bool	parse_metalness(char const *element, void *value)
{
	bool *const	metalness = (bool *)value;

	if (ft_strcmp("true", element) == 0)
		*metalness = true;
	else if (ft_strcmp("false", element) == 0)
		*metalness = false;
	else
	{
		print_line_error(ERROR_METALNESS_VALUE, NULL);
		return (false);
	}
	return (true);
}
