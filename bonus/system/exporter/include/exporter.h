/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exporter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORTER_H
# define EXPORTER_H

# include <stdbool.h>

# define PPM_OPTION "--ppm"

bool	export_ppm(char const *scene_path);

#endif
