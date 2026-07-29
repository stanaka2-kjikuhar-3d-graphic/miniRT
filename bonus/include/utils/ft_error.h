/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 19:01:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stddef.h>

/* File */
# define ERROR_FILE_BINARY "not a text file"

/* Identifier / Scene */
# define ERROR_ID_UNKNOWN "unknown identifier"
# define ERROR_ID_DUP_A "duplicate ambient lighting (A)"
# define ERROR_ID_DUP_C "duplicate camera (C)"
# define ERROR_ID_NO_A "missing ambient lighting (A)"
# define ERROR_ID_NO_L "missing light (L)"
# define ERROR_ID_NO_C "missing camera (C)"

/* Element count */
# define ERROR_FIELDS_COUNT "invalid fields count"
# define HINT_A "A brightness R,G,B"
# define HINT_L "L x,y,z brightness R,G,B"
# define HINT_C "C x,y,z nx,ny,nz fov"
# define HINT_SP "sp x,y,z diameter R,G,B"
# define HINT_PL "pl x,y,z nx,ny,nz R,G,B"
# define HINT_CY "cy x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_CO "co x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_HB "hb x,y,z nx,ny,nz center_diameter cap_diameter height R,G,B"
# define HINT_PB "pb x,y,z nx,ny,nz coefficient height R,G,B"
# define HINT_SL "sl x,y,z brightness R,G,B nx,ny,nz angle"

/* Field syntax */
# define ERROR_INVALID_FORMAT "invalid format"
# define ERROR_INVALID_CHARACTER "invalid character"
# define ERROR_LEADING_ZERO "leading zero not allowed"
# define ERROR_ONLY_DIGITS "only digits allowed"
# define ERROR_EMPTY_COMPONENT "empty component"
# define ERROR_EMPTY_CHANNEL "empty channel"

/* Field value */
# define ERROR_MUST_BE_POSITIVE "must be positive"
# define ERROR_MUST_BE_NON_NEGATIVE "must be non-negative"
# define ERROR_MUST_BE_BOOL "must be true or false"
# define ERROR_MUST_BE_NORMALIZED "must be a unit vector"
# define ERROR_TOO_SMALL "too small, half of it underflows to 0"
# define ERROR_BRIGHTNESS_RANGE "out of range (0.0 <= x <= 1.0)"
# define ERROR_FOV_RANGE "out of range (0 < x < 180)"
# define ERROR_ANGLE_RANGE "out of range (0 <= x <= 180)"
# define ERROR_COLOR_RANGE "out of range (0 <= x <= 255)"
# define ERROR_HB_RADIUS "cap_diameter must exceed center_diameter"
# define HINT_VECTOR "x,y,z"
# define HINT_COLOR "R,G,B (0-255)"

/* Material option */
# define ERROR_OPTION_FORMAT "option: missing '=' separator"
# define ERROR_OPTION_UNKNOWN "option: unknown option"
# define ERROR_OPTION_DUP "option: duplicate option"
# define HINT_OPTION_FORMAT "key=value"

/* MLX */
# define ERROR_MLX_CONNECTION "failed to create X-Window connection"
# define ERROR_MLX_WINDOW "failed to create window"
# define ERROR_MLX_IMAGE "failed to create image"
# define ERROR_MLX_XPM_IMAGE "failed to create xpm image"
# define ERROR_MLX_IMAGE_DATA "failed to get image data"

void	print_error(char const *msg);
void	print_argument_error(char const *program_name);
void	print_texture_error(char const *path, char const *msg);
void	print_errno(void);
void	set_error_line_number(size_t line_number);
void	set_error_string(char const *line_str);
void	set_error_strings(char const **line_strs);
void	set_error_field(char const *field);
void	print_line_error(char const *msg, char const *hint);
void	print_line_error_multi_hints(char const *msg, char const **hints);
void	print_field_error(char const *msg, char const *hint);

#endif
