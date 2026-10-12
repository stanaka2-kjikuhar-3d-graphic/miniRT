/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:46:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 22:43:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_PRIVATE_H
# define HOOK_PRIVATE_H

# include <stdbool.h>

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

#endif
