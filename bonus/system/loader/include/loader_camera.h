/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_camera.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:41:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 07:31:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_CAMERA_H
# define LOADER_CAMERA_H

# include "vector.h"

typedef struct s_camera_input
{
	t_vec3	pos;
	t_vec3	dir;
	float	fov;
}	t_camera_input;

#endif
