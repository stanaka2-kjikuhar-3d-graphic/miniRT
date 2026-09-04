/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 17:21:43 by stanaka2         ###   ########.fr       */
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

bool	check_render_flag(void);
void	phong(t_ivec2 pixel);
void	put_color_to_window_image(t_ivec2 pixel, t_color color);

#endif
