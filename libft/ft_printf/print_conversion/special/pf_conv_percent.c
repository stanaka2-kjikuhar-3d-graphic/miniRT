/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:44:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/27 07:02:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf/print_utils.h"
#include "ft_printf/types.h"

void	pf_conv_percent(t_ctx *ctx, t_conv *conv)
{
	(void)conv;
	pf_print_char(ctx, '%');
}
