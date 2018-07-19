/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 22:47:00 by pblouin          ###   ########.fr       */
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
** Parser Function
*/
t_data	*ft_parser(const char *format);

/*
** Formatter Function
*/
void	ft_formatter(t_data *list, va_list ap);
void	ft_format_router(t_data *data, va_list ap);

/*
** TESTS
*/
void test_format_01();

#endif