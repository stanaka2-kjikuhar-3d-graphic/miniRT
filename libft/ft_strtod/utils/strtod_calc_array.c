/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_calc_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 22:09:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

#include "../ft_strtod_internal.h"

static void	update_lsb_and_msb(t_to_double *to_doubleb);

void	strtod_half_array(t_to_double *to_double)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = to_double->lsb;
	right = to_double->msb;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*left += carry * to_double->base;
		carry = *left % 2;
		*left = *left / 2;
		++left;
	}
	if (carry != 0 && left <= to_double->end)
	{
		*left = (carry * to_double->base) / 2;
		to_double->msb = left;
	}
	update_lsb_and_msb(to_double);
}

void	strtod_double_array(t_to_double *to_double)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = to_double->lsb;
	right = to_double->msb;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*right = *right * 2 + carry;
		carry = *right / to_double->base;
		*right %= to_double->base;
		--right;
	}
	if (carry != 0 && to_double->fixed_point <= right)
	{
		*right = carry;
		to_double->lsb = right;
	}
	update_lsb_and_msb(to_double);
}

static void	update_lsb_and_msb(t_to_double *to_double)
{
	if (to_double->lsb == NULL || to_double->msb == NULL)
		return ;
	while (to_double->lsb <= to_double->msb)
	{
		if (*(to_double->lsb) != 0)
			break ;
		++(to_double->lsb);
	}
	if (to_double->lsb > to_double->msb)
	{
		to_double->lsb = NULL;
		to_double->msb = NULL;
		return ;
	}
	while (to_double->lsb <= to_double->msb)
	{
		if (*(to_double->msb) != 0)
			break ;
		--(to_double->msb);
	}
}
