/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/10 23:26:48 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_PRIVATE_H
# define RENDERER_PRIVATE_H

# include <stdbool.h>

# include "config.h"
# include "object.h"
# include "vector.h"
# include "color.h"
# include "aabb.h"
# include "ray.h"

bool	check_render_flag(void);
t_ray	calc_camera_ray(t_ivec2 pixel);
void	phong(t_ivec2 pixel);
void	raytrace_pixel(t_ivec2 pixel);
void	put_color_to_window_image(t_ivec2 pixel, t_color color);

#endif
