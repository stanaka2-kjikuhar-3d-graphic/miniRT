/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:36:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 22:35:22 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H

# include "ray.h"
# include "color.h"

# include "intersection.h"

t_color	phong_lighting(t_ray const *ray, t_hit const *hit);

#endif
