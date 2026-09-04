/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_accelerator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:10:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 17:55:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "./accelerator_private.h"

bool	build_accelerator(void)
{
	if (!build_bvh())
		return (false);
	if (!build_infinite_objects())
		return (false);
	return (true);
}
