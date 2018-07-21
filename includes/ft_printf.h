/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 14:43:32 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "ft_struct.h"

/* UTILS */
# include "ft_utils_parser.h"
# include "ft_utils_list.h"
# include "ft_utils_test.h"

# define TYPES "sSpdDioOuUxXcC"

/*
** Parser function
*/
t_data	*ft_parser(const char *format);

/*
** Formatter functions
*/
void	ft_formatter(t_data *list, va_list ap);
void	ft_format_router(t_data *data, va_list ap);
void 	ft_format_width_handler(t_data *data);
void	ft_format_plus_flag_handler(t_data *elem);
/*
** Printer functions
*/
void	ft_printer(t_data *data);

/*
** Tests functions
*/
void test_format_01();

#endif