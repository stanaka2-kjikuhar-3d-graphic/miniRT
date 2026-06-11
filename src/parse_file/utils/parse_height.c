/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 23:49:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_height(char const *element, double *height)
{
	if (!parse_double(element, height))
		return (false);
	if (*height <= 0.0)
	{
		print_error("");
		return (false);
	}
	return (true);
}
