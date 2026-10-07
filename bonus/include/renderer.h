/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:55:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 21:18:32 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdbool.h>

enum e_render_mode
{
	RENDER_MODE_RAYTRACE,
	RENDER_MODE_PHONG,
	RENDER_MODE_COUNT
};

bool				renderer(void);
void				set_render_flag(bool status);
enum e_render_mode	get_render_mode(void);
void				set_render_mode(enum e_render_mode mode);

#endif
