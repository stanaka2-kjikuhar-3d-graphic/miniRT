/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:19:48 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:20:32 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

/* p^T Q p = dot(p, Q * p). See docs/quadric.md. */
float	quadric_eval(t_mat4 q, t_vec4 p)
{
	return (vec4_dot(p, mat4_mul_vec4(q, p)));
}
