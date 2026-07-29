/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:05:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:21:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_error_private.h"

static char const	*g_error_field;

void	set_error_field(char const *field)
{
	g_error_field = field;
}

char const	*get_error_field(void)
{
	if (g_error_field == NULL)
		return ("");
	return (g_error_field);
}
