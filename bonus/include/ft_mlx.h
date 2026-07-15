/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 12:28:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <stdbool.h>

# include "color.h"

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

bool			create_mlx_connection(void);
bool			setup_mlx_window(void);
bool			create_window(int width, int height, char *title);
bool			create_image(enum e_image_id id, int width, int height);
bool			create_texture(char *filepath);
void			cleanup_mlx(void);
void			setup_mlx_hooks(void);
void			*get_mlx_ptr(void);
void			*get_win_ptr(void);
t_image			*get_image(enum e_image_id id);
t_image			*get_texture(char *filepath);
unsigned int	*get_pixel_addr(t_image *image, int x, int y);
t_color			get_uv_pixel_color(t_image *image, float u, float v);

#endif
