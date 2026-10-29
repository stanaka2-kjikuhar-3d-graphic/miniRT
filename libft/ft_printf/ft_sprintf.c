/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:49:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/27 07:02:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include <stdarg.h>
#include <stddef.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/types.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	t_ctx	ctx;
	va_list	ap;

	if (format == NULL)
		return (-1);
	ft_bzero(&ctx, sizeof(t_ctx));
	ctx.dst_type = PRINT_TO_STR;
	ctx.dst.str = str;
	ctx.dst_size = SIZE_MAX;
	ctx.dst.str[0] = '\0';
	va_start(ap, format);
	pf_xprintf(&ctx, &ap, format);
	va_end(ap);
	if (ctx.has_error)
		return (PF_ERROR);
	return ((int)ctx.count);
}
