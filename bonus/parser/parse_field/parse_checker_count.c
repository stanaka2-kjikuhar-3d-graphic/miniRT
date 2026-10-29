/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:22:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/22 23:23:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../parser_private.h"

bool	parse_checker_count(char const *element, int *checker_count)
{
	long	num;

	if (!parse_long(element, &num))
		return (false);
	if (num < 2 || 1024 < num)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_CHECKER_COUNT);
		return (false);
	}
	*checker_count = (int)num;
	return (true);
}
