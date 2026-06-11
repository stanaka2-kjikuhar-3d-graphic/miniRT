/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_diameter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:40:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 23:49:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_diameter(char const *element, double *diameter)
{
	if (!parse_double(element, diameter))
		return (false);
	if (*diameter <= 0.0)
	{
		print_error("");
		return (false);
	}
	return (true);
}
