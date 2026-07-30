/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:05:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 01:27:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_error_private.h"

static char const	*g_error_field;
static char const	*g_error_token;

void	set_error_field_and_token(char const *field, char const *token)
{
	g_error_field = field;
	g_error_token = token;
}

char const	*get_error_field(void)
{
	return (g_error_field);
}

char const	*get_error_token(void)
{
	return (g_error_token);
}
