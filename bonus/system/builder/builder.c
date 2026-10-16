/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:37:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:32:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "accelerator.h"
#include "camera.h"
#include "vector.h"

#include "./builder_private.h"

bool	builder(void)
{
	if (!rebase_world_space(vec3(0.0f, 0.0f, 0.0f)) \
		|| !build_accelerator())
	{
		return (false);
	}
	return (true);
}
