/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORTER_PRIVATE_H
# define EXPORTER_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# define RT_EXTENSION ".rt"
# define PPM_EXTENSION ".ppm"
# define PPM_MAX_VALUE 255

char	*calc_ppm_path(char const *scene_path);
bool	write_ppm_header(int fd);
bool	write_ppm_row(int fd, int y);
bool	write_bytes(int fd, char const *buf, size_t size);

#endif
