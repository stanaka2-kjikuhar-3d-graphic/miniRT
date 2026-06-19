/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 02:58:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PRIVATE_H
# define FT_MLX_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "vector.h"

typedef struct s_key
{
	bool	shift;
}	t_key;

void	cleanup_mlx_connection(void);
void	cleanup_window(void);
void	cleanup_images(void);
int		draw_hook(void *param);
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		button_press_hook(unsigned int button, int x, int y);
int		button1_motion_hook(int x, int y);

#endif
