/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:48:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/11 18:29:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

int	expose_hook(void *param);
int	loop_hook(void *param);
int	key_press_hook(int keycode, void *param);
int	key_release_hook(int keycode, void *param);
int	button_press_hook(unsigned int button, int x, int y);
int	button_release_hook(unsigned int button, int x, int y);
int	button1_motion_hook(int x, int y);

#endif
