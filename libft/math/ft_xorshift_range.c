/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xorshift_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 23:37:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/31 23:46:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_math.h"

float	ft_xorshift_range(uint32_t *seed, float min, float max)
{
	float	rand;

	rand = (float)(ft_xorshift(seed)) / (float)UINT32_MAX;
	return (min + (max - min) * rand);
}
