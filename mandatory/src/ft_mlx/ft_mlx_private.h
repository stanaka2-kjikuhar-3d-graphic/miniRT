/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 19:12:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PRIVATE_H
# define FT_MLX_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "vector.h"
# include "ft_mlx.h"

enum e_camera_action
{
	CAMERA_ACTION_MOVE_FORWARD,
	CAMERA_ACTION_MOVE_BACK,
	CAMERA_ACTION_MOVE_RIGHT,
	CAMERA_ACTION_MOVE_LEFT,
	CAMERA_ACTION_MOVE_UP,
	CAMERA_ACTION_MOVE_DOWN
};

typedef struct s_key
{
	bool	shift;
}	t_key;

typedef struct s_texture_dict
{
	t_image	*texture;
	char	*filepath;
}	t_texture_dict;

void	cleanup_mlx_connection(void);
void	cleanup_window(void);
void	cleanup_images(void);
void	cleanup_textures(void);
int		expose_hook(void *param);
int		loop_hook(void *param);
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		button_press_hook(unsigned int button, int x, int y);
int		button_release_hook(unsigned int button, int x, int y);
int		button1_motion_hook(int x, int y);

#endif
