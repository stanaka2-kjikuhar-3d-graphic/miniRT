/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:39:37 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 23:20:31 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_PRIVATE_H
# define RAYTRACER_PRIVATE_H

# include "ray.h"
# include "color.h"

t_color	trace_ray(t_ray ray, int depth);

#endif
