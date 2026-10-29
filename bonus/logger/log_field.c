/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:05:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:41:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

#include "./logger_private.h"

static char const	*g_log_field;
static char const	*g_log_token;

void	set_log_field(char const *field, char const *token)
{
	g_log_field = field;
	g_log_token = token;
}

char const	*get_log_field(void)
{
	return (g_log_field);
}

char const	*get_log_token(void)
{
	return (g_log_token);
}
