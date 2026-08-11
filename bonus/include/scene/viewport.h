/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 00:24:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/07 23:19:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include <stdbool.h>

# include "vector.h"

typedef struct s_viewport
{
	t_ivec2		pixel_size;
	int			pixel_count;
	t_vec2		pixel_half_size;
	float		aspect_ratio;
	float		fov;
	t_vec2		world_half_size;
}	t_viewport;

// input
typedef struct s_input_viewport
{
	float	fov;
}	t_input_viewport;

t_viewport const	*get_viewport(void);
void				set_viewport(t_input_viewport const *input);
bool				change_viewport_fov(float degree);

#endif
