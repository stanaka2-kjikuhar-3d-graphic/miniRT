/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:23:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:24:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_PRIVATE_H
# define FT_ERROR_PRIVATE_H

# include <stddef.h>

size_t		get_error_line_number(void);
char const	*get_error_string(void);
char const	*get_error_field(void);

#endif
