/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:55:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/31 21:03:34 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stdbool.h>

enum e_phong_mode
{
	PHONG_MODE_PHONG,
	PHONG_MODE_BLINN_PHONG,
	PHONG_MODE_COUNT
};

bool				renderer(void);
void				set_render_flag(bool status);
enum e_phong_mode	get_phong_mode(void);
void				set_phong_mode(enum e_phong_mode mode);

#endif
