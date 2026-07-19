/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_from_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:48:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/19 18:14:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* Direction (w = 0): translation-invariant. See docs/matrix.md. */
t_vec4	vec4_from_dir(t_vec3 v)
{
	return ((t_vec4){.x = v.x, .y = v.y, .z = v.z, .w = 0.0f});
}
