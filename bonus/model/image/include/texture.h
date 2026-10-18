/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:36:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:34:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stdbool.h>

# include "id.h"
# include "vector.h"

typedef t_id	t_texture_id;

bool			create_texture(char *filepath, t_texture_id *id);
unsigned int	get_texture_pixel(t_texture_id id, t_ivec2 pixel);
unsigned int	get_texture_uv_pixel(t_texture_id id, t_vec2 uv);
t_ivec2			get_texture_size(t_texture_id id);

#endif
