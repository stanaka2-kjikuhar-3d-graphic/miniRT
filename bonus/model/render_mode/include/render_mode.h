/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 17:40:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 17:46:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MODE_H
# define RENDER_MODE_H

enum e_render_mode
{
	RENDER_MODE_RAYTRACE,
	RENDER_MODE_PHONG,
	RENDER_MODE_COUNT
};

enum e_phong_mode
{
	PHONG_MODE_PHONG,
	PHONG_MODE_BLINN_PHONG,
	PHONG_MODE_COUNT
};

enum e_render_mode	get_render_mode(void);
void				set_render_mode(enum e_render_mode mode);
enum e_phong_mode	get_phong_mode(void);
void				set_phong_mode(enum e_phong_mode mode);

#endif
