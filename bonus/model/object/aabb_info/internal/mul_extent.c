/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_extent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:55:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 19:32:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Avoid resulting in NaN when multiplying infinity by 0.0f.
Return 0.0 if either operand is 0.0f.
*/
float	mul_extent(float a, float b)
{
	if (a == 0.0f || b == 0.0f)
		return (0.0f);
	return (a * b);
}
