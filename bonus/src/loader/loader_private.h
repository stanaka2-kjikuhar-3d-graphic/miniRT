/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:13:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:16:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_PRIVATE_H
# define LOADER_PRIVATE_H

# include <stdbool.h>

# include "loader.h"

bool	create_camera(t_scene_input const *scene_input);
bool	create_ambient_light(t_scene_input const *scene_input);
bool	create_uniform_infinite_light(t_scene_input const *scene_input);
bool	create_point_light(t_scene_input const *scene_input);
bool	create_spot_light(t_scene_input const *scene_input);
bool	create_directional_light(t_scene_input const *scene_input);
bool	create_sphere(t_scene_input const *scene_input);
bool	create_plane(t_scene_input const *scene_input);
bool	create_cylinder(t_scene_input const *scene_input);
bool	create_disc(t_scene_input const *scene_input);
bool	create_cone(t_scene_input const *scene_input);
bool	create_hyperboloid(t_scene_input const *scene_input);
bool	create_paraboloid(t_scene_input const *scene_input);

typedef struct s_loader
{
	bool	(*load)(t_scene_input const *);
}	t_loader;

#endif
