/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 00:13:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:59:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_PRIVATE_H
# define LOADER_PRIVATE_H

# include <stdbool.h>

# include "loader.h"

bool	load_camera(t_scene_input const *scene_input);
bool	load_ambient_light(t_scene_input const *scene_input);
bool	load_uniform_infinite_light(t_scene_input const *scene_input);
bool	load_point_light(t_scene_input const *scene_input);
bool	load_spot_light(t_scene_input const *scene_input);
bool	load_directional_light(t_scene_input const *scene_input);
bool	load_sphere(t_scene_input const *scene_input);
bool	load_plane(t_scene_input const *scene_input);
bool	load_cylinder(t_scene_input const *scene_input);
bool	load_disc(t_scene_input const *scene_input);
bool	load_cone(t_scene_input const *scene_input);
bool	load_hyperboloid(t_scene_input const *scene_input);
bool	load_paraboloid(t_scene_input const *scene_input);

typedef struct s_loader
{
	bool	(*load)(t_scene_input const *);
}	t_loader;

#endif
