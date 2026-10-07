/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:36:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/04 22:07:58 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H

# include "ray.h"
# include "color.h"

# include "intersection.h"

enum e_phong_mode
{
	PHONG_MODE_PHONG,
	PHONG_MODE_BLINN_PHONG,
	PHONG_MODE_COUNT
};

t_color				phong_lighting(t_ray const *ray, t_hit const *hit);
enum e_phong_mode	get_phong_mode(void);
void				set_phong_mode(enum e_phong_mode mode);

#endif
