/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:09:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 21:19:57 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_PRIVATE_H
# define INTERSECTION_PRIVATE_H

# include <stdbool.h>

# include "ray.h"

# include "intersection.h"

void	bvh_intersection(t_hit *hit, t_ray const *ray);
void	infinite_objects_intersection(t_hit *hit, t_ray const *ray);
bool	bvh_shading(t_ray const *ray, float dist);
bool	infinite_objects_shading(t_ray const *ray, float dist);

#endif
