/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:38:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"

#include "../ft_strtod_internal.h"

void	set_sign(t_to_double *to_double)
{
	if (to_double->is_negative)
		to_double->sign = (uint64_t)1;
}
