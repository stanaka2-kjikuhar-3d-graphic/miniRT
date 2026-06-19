/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:32:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:11:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "ft_mlx.h"

int	button_press_hook(unsigned int button, int x, int y)
{
	(void)button;
	(void)x;
	(void)y;
	return (0);
}
