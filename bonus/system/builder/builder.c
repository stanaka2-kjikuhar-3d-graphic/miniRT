/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:37:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 16:59:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "camera.h"
#include "vector.h"

#include "./builder_private.h"

bool	builder(void)
{
	if (!build_accelerator())
	{
		return (false);
	}
	return (true);
}
