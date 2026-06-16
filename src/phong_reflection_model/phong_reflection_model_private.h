/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_reflection_model_private.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:35:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 23:52:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_REFLECTION_MODEL_PRIVATE_H
# define PHONG_REFLECTION_MODEL_PRIVATE_H

#include "object.h"

typedef struct s_hit
{
	t_object const	*object;
	double			t;
}	t_hit;

t_hit	intersects(t_ray const *ray);

#endif
