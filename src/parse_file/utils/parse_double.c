/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:25:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 19:42:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_double(char const *s, double *value)
{
	*value = ft_atof(s);
	if (!parse_floating_point_format(&s))
		return (false);
	if (*s != '\0')
	{
		print_error("");
		return (false);
	}
	return (true);
}