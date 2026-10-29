/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:53:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:42:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_PRIVATE_H
# define IMAGE_PRIVATE_H

# include <assert.h>

# include "vector.h"

static_assert(sizeof(int) == 4, "Error\n32bit int type is required");

typedef struct s_image
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

void			cleanup_textures(void);
void			cleanup_window_buffers(void);

t_ivec2			calc_image_uv_pixel(t_image const *image, t_vec2 uv);
unsigned int	*get_image_pixel_addr(t_image *image, t_ivec2 pixel);
unsigned int	get_image_pixel(t_image const *image, t_ivec2 pixel);
unsigned int	get_image_uv_pixel(t_image const *image, t_vec2 uv);

#endif
