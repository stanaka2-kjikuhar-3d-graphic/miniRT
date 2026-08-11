/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/09 00:47:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "camera.h"
#include "renderer.h"

#include "../ft_mlx_private.h"

static void	camera_move_action(enum e_camera_action action);

int	key_press_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == XK_Escape)
		mlx_loop_end(get_mlx_ptr());
	if (keycode == XK_w)
		camera_move_action(CAMERA_ACTION_MOVE_FORWARD);
	else if (keycode == XK_s)
		camera_move_action(CAMERA_ACTION_MOVE_BACK);
	else if (keycode == XK_Right || keycode == XK_d)
		camera_move_action(CAMERA_ACTION_MOVE_RIGHT);
	else if (keycode == XK_Left || keycode == XK_a)
		camera_move_action(CAMERA_ACTION_MOVE_LEFT);
	else if (keycode == XK_Up)
		camera_move_action(CAMERA_ACTION_MOVE_UP);
	else if (keycode == XK_Down)
		camera_move_action(CAMERA_ACTION_MOVE_DOWN);
	return (0);
}

static void	camera_move_action(enum e_camera_action action)
{
	t_camera const	*camera;

	camera = get_camera();
	if (action == CAMERA_ACTION_MOVE_FORWARD)
		change_camera_pos(vec3_add(camera->pos, camera->dir));
	else if (action == CAMERA_ACTION_MOVE_BACK)
		change_camera_pos(vec3_add(camera->pos, vec3_scale(-1, camera->dir)));
	else if (action == CAMERA_ACTION_MOVE_RIGHT)
		change_camera_pos(vec3_add(camera->pos, camera->right));
	else if (action == CAMERA_ACTION_MOVE_LEFT)
		change_camera_pos(vec3_add(camera->pos, vec3_scale(-1, camera->right)));
	else if (action == CAMERA_ACTION_MOVE_UP)
		change_camera_pos(vec3_add(camera->pos, camera->up));
	else if (action == CAMERA_ACTION_MOVE_DOWN)
		change_camera_pos(vec3_add(camera->pos, vec3_scale(-1, camera->up)));
	set_render_flag(true);
}
