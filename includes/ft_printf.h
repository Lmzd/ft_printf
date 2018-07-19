/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/19 16:57:52 by lmazeaud         ###   ########.fr       */
=======
/*   Updated: 2018/07/18 16:27:16 by pblouin          ###   ########.fr       */
>>>>>>> c2620537f1ceb5615eabf7797800ab4fcf215aa5
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


/*
** TESTS
*/

void test_format_01();

/*
** TESTS
*/

void test_format_01();

#endif