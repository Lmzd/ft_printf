/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 12:38:31 by lmazeaud         ###   ########.fr       */
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
t_data	        *ft_parser(const char *format, va_list ap);


#endif