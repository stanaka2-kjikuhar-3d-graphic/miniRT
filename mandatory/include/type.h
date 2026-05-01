/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:44:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 02:05:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

// struct
typedef struct s_cub3d		t_cub3d;
typedef struct s_setting	t_setting;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_dvec2		t_dvec2;
typedef struct s_ivec2		t_ivec2;
typedef struct s_color		t_color;
typedef struct s_mlx		t_mlx;
typedef struct s_img		t_img;
typedef struct s_assets		t_assets;
typedef struct s_hit		t_hit;
typedef struct s_wall		t_wall;

// enum
typedef enum e_hit_side		t_hit_side;

// function
typedef bool				(*t_setting_setter)(t_setting *, char *);

#endif