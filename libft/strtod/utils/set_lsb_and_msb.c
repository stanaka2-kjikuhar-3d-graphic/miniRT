/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lsb_and_msb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:28:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 18:32:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_strtod_internal.h"

void	set_lsb_and_msb(t_to_double *to_double)
{
	size_t	i;

	i = 0;
	while (i < BUF_SIZE)
	{
		if (to_double->fixed_point[i] != 0)
		{
			if (to_double->lsb == NULL)
				to_double->lsb = &(to_double->fixed_point[i]);
			to_double->msb = &(to_double->fixed_point[i]);
		}
		++i;
	}
}
