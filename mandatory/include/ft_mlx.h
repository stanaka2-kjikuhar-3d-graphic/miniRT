/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:19:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 03:41:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "type.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define COLOR_BIT_SIZE 32
# define TEXTURE_SIZE 64

struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*pixel;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_assets
{
	t_img	north_wall;
	t_img	south_wall;
	t_img	west_wall;
	t_img	east_wall;
};

struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	int			width;
	int			height;
	t_assets	assets;
};

bool			ft_mlx_init(t_mlx *mlx, t_setting *setting);
bool			create_connection(t_mlx *mlx);
bool			create_window(t_mlx *mlx);
bool			create_win_image(t_mlx *mlx, t_img *win_img);
bool			create_assets(t_mlx *mlx, t_setting *setting);
void			init_image_info(t_img *img, int width, int height);
unsigned int	*get_pixel_addr(const t_img *img, const int x, const int y);
void			ft_mlx_hooks(t_cub3d *cub3d);
int				expose_hook(t_cub3d *cub3d);
int				key_press_hook(int keycode, t_cub3d *cub3d);
int				key_release_hook(int keycode, t_cub3d *cub3d);
int				button_press_hook(\
					unsigned int button, int x, int y, t_cub3d *cub3d);
int				button1_motion_hook(int x, int y, t_cub3d *cub3d);
int				loop_hook(t_cub3d *cub3d);
void			ft_mlx_destroy(t_mlx *mlx);

#endif
