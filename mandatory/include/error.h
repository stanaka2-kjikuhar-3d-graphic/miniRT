/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:59:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/06 17:03:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARG_USAGE "Usage: ./miniRT <*.rt>"
# define ERROR_FILE_EXTENSION "File must have a '.rt' extension."

# define ERROR_SETTING_INCOMPLETE \
			"Missing required settings. Expected: NO SO WE EA F C"
# define ERROR_SETTING_UNKNOWN_ID "Unknown identifier. Valid: NO SO WE EA F C"
# define ERROR_SETTING_ONLY_SPACE "Setting line must have identifier and value"
# define ERROR_SETTING_MISSING_VALUE "Setting value is required."
# define ERROR_SETTING_EXTRA_VALUE "Setting must have a single value."
# define ERROR_SETTING_DUPLICATE "Duplicate setting detected."

# define ERROR_COLOR_FORMAT "Invalid color format. Expected: R,G,B (0-255)"
# define ERROR_COLOR_LEADING_ZERO "Color value cannot have a leading zero."
# define ERROR_COLOR_RANGE "Color value out of range (0-255)."

# define ERROR_MAP_TOO_LARGE "Map is too large."
# define ERROR_MAP_EMPTY "Map is empty."
# define ERROR_MAP_EMPTY_LINE "Map cannot have an empty line."
# define ERROR_MAP_INVALID_CHAR "Invalid map element detected."
# define ERROR_MAP_NOT_CLOSED "Map is not closed/surrounded by walls."
# define ERROR_MAP_MULTI_PLAYER "Multiple player elements detected."
# define ERROR_MAP_NO_PLAYER "Map requires a player element. Expected: N S W E"

void	print_error(char *error_msg);

#endif
