/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 22:28:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdbool.h>

bool	create_mlx_connection(void);
bool	setup_mlx_window(void);
bool	create_window(int width, int height, char *title);
void	cleanup_mlx(void);
void	setup_mlx_hooks(void);
void	*get_mlx_ptr(void);
void	*get_win_ptr(void);

#endif
