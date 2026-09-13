/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_factory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:01:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 16:40:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_FACTORY_H
# define CAMERA_FACTORY_H

# include "vector.h"

typedef struct s_input_camera
{
	t_vec3	pos;
	t_vec3	dir;
	float	fov;
}	t_input_camera;

void	create_camera(t_input_camera const *input);

#endif
