/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 17:54:11 by stanaka2         ###   ########.fr       */
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
# define HINT_A "A ratio R,G,B"
# define HINT_L "L x,y,z brightness R,G,B"
# define HINT_C "C x,y,z nx,ny,nz fov"
# define HINT_SP "sp x,y,z diameter R,G,B"
# define HINT_PL "pl x,y,z nx,ny,nz R,G,B"
# define HINT_CY "cy x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_CO "co x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_HB "hb x,y,z nx,ny,nz center_diameter cap_diameter height R,G,B"
# define HINT_PB "pb x,y,z nx,ny,nz coefficient height R,G,B"
# define HINT_SL "sl x,y,z brightness R,G,B, nx,ny,nz angle"

/* Element */
# define ERROR_BRIGHTNESS_RANGE "brightness: out of range (0.0 <= x <= 1.0)"
# define ERROR_FOV_RANGE "fov: out of range (0 < x < 180)"
# define ERROR_DIR_NOT_NORMALIZED "direction: must be a unit vector"
# define ERROR_DIAMETER_RANGE "diameter: must be positive"
# define ERROR_DIAMETER_SMALL "diameter: too small, diameter/2 underflows to 0"
# define ERROR_HB_RADIUS "hb: cap_diameter must exceed center_diameter"
# define ERROR_SIZE_RANGE "number: must be positive"
# define ERROR_HEIGHT_RANGE "height: must be positive"
# define ERROR_HEIGHT_SMALL "height: too small, height/2 underflows to 0"
# define ERROR_ANGLE_RANGE "angle: out of range (0 <= x <= 180)"
# define ERROR_SHININESS_RANGE "shininess: must be non-negative"
# define ERROR_BOOL_VALUE "boolean: must be true or false"

/* Floating Number */
# define ERROR_FLOAT_CHARACTER "number: invalid character"
# define ERROR_FLOAT_LEADING_ZERO "number: leading zero not allowed"

/* Vector */
# define ERROR_VECTOR_EMPTY "vector: empty component"
# define ERROR_VECTOR_FORMAT "vector: invalid format"
# define ERROR_VECTOR_CHARACTER "vector: invalid character"
# define ERROR_VECTOR_LEADING_ZERO "vector: leading zero not allowed"
# define HINT_VECTOR "x,y,z"

/* Color */
# define ERROR_COLOR_EMPTY "color: empty channel"
# define ERROR_COLOR_FORMAT "color: invalid format"
# define ERROR_COLOR_NON_DIGIT "color: only digits allowed"
# define ERROR_COLOR_LEADING_ZERO "color: leading zero not allowed"
# define ERROR_COLOR_RANGE "color: out of range (0 <= x <= 255)"
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
void	set_error_line_no(size_t line_no);
void	set_error_line_str(char const *line_str);
void	set_error_line_multi_strs(char const **line_strs);
void	print_line_error(char const *msg, char const *hint);
void	print_line_error_multi_hints(char const *msg, char const **hints);

#endif
