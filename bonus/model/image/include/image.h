/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:53:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 16:59:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdbool.h>
# include <assert.h>

# include "vector.h"

static_assert(sizeof(int) == 4, "Error\n32bit int type is required");

enum e_image_id
{
	IMG_WINDOW,
	IMG_COUNT,
};

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

bool			create_image(enum e_image_id id, int width, int height);
bool			create_texture(char *filepath);
t_image			*get_image(enum e_image_id id);
t_image			*get_texture(char *filepath);
unsigned int	*get_pixel_addr(t_image *image, t_ivec2 pixel);
t_ivec2			calc_uv_pixel(t_image *image, t_vec2 uv);
unsigned int	*get_uv_pixel_addr(t_image *image, t_vec2 uv);
void			put_color(t_image *image, t_ivec2 pixel, int color);

#endif
