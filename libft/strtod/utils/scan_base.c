/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:39:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 20:55:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "../ft_strtod_internal.h"

void	scan_base(const char **nptr, t_to_double *to_double)
{
	if (ft_strncmp("0x", *nptr, 2) == 0 \
		|| ft_strncmp("0X", *nptr, 2) == 0)
	{
		to_double->base = 16;
		*nptr += 2;
	}
	else
		to_double->base = 10;
}
