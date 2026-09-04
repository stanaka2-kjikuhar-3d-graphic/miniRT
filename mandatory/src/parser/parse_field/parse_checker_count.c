/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:22:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 01:59:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_checker_count(char const *element, void *value)
{
	int *const	checker_count = (int *)value;
	long		num;

	if (!parse_long(element, &num))
		return (false);
	if (num < 2 || 1024 < num)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_CHECKER_COUNT);
		return (false);
	}
	*checker_count = (int)num;
	return (true);
}
