/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 02:44:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <stdbool.h>

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
bool			create_window(int width, int height, char *title);
bool			create_image(enum e_image_id id, int width, int height);
void			*get_mlx_ptr(void);
void			*get_win_ptr(void);
t_image			*get_image(enum e_image_id id);
void			ft_mlx_hooks(void);
void			ft_mlx_destroy(void);
unsigned int	*get_pixel_addr(t_image *image, int x, int y);

#endif
