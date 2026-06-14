/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_floating_point_format.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:26:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 06:33:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"

bool	is_valid_floating_point_format(const char *s)
{
	if (ft_isspace(*s))
		return (false);
	if (*s == '+' || *s == '-')
		++s;
	if (ft_isdigit(*s))
		return (false);
	return (true);
}
