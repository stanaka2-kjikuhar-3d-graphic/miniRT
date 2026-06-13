/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:55:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 20:59:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_strtod_internal.h"

void	scan_sign(const char **nptr, t_to_double *to_double)
{
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			to_double->sign = 1ULL;
		++(*nptr);
	}
}
