/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_obj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:54:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/29 21:40:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_OBJ_H
# define LOADER_OBJ_H

# include "ft_lst.h"

typedef struct s_obj_input
{
	t_list	*v_list;
	t_list	*vn_list;
	t_list	*vt_list;
	t_list	*f_list;
}   t_obj_input;

#endif