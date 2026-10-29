/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:17:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/29 22:37:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"
#include "loader_obj.h"

void	delete_obj_input(void *scene_input)
{
	t_obj_input	obj_input;

	if (scene_input == NULL)
		return ;
	obj_input = ((t_scene_input *)scene_input)->obj;
	ft_lstclear(obj_input.v_list, free);
	ft_lstclear(obj_input.vn_list, free);
	ft_lstclear(obj_input.vt_list, free);
	ft_lstclear(obj_input.f_list, free);
	free(scene_input);
}