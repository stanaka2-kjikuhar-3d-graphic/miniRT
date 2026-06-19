/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:57:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 00:59:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# ifdef __APPLE__
#  define WINDOW_WIDTH 1280
#  define WINDOW_HEIGHT 780
# else
#  define WINDOW_WIDTH 1920
#  define WINDOW_HEIGHT 1080
# endif

# define WINDOW_TITLE "miniRT"

#endif
