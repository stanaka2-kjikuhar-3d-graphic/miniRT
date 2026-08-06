/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:19:48 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:21:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

float	quadric_eval(t_mat4 const *q, t_vec4 p)
{
	return (vec4_dot(p, mat4_mul_vec4(q, p)));
}
