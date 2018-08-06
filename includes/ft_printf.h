/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 07:48:50 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include "../libft/includes/libft.h"
# include "ft_struct.h"
# include "ft_utils_parser.h"
# include "ft_utils_list.h"
# include "ft_utils_test.h"

# define TYPES          "sSpdDioOuUxXcC%"
# define CHAR_ON        " .+-0#lhzj123456789sSpdDioOuUxXcC%"
# define HEX_PREFIX     "0x"

t_data	*ft_parser(const char *format);

void	ft_formatter(t_data *list, va_list ap);
void	ft_format_router(t_data *data, va_list ap);
void	ft_format_width_handler(t_data *data);
void	ft_format_plus_flag_handler(t_data *elem);
void	ft_format_moins_flag_handler(t_data *elem);
void	ft_format_space_flag_handler(t_data *elem);
void	ft_format_moins_flag_space_or_plus_handler(t_data *elem);
void	ft_format_precision_handler(t_data *elem);
void	ft_format_precison_width_handler(t_data *elem);
void	ft_format_precision_moins_flag_handler(t_data *elem);
void	ft_format_null_value(t_data *elem);
void	ft_format_hash_handler(t_data *elem);
void	ft_format_hex_width_handler(t_data *elem);
void	ft_format_hex_width_zero_flag(t_data *elem, char *prefix, \
	char *str, int width);
void	ft_format_hex_precision_width_handler(t_data *elem);
void	ft_format_hex_precision_moins_flag_handler(t_data *elem);
void	ft_format_hex_precision_handler(t_data *elem);
void	ft_format_hex_moins_flag_handler(t_data *elem);
void	ft_format_hex_null_value(t_data *elem);
void	ft_format_str_flags(t_data *elem);
void	ft_format_str_moins_flag_handler(t_data *elem);
void	ft_format_str_precision_handler(t_data *elem);
void	ft_format_str_width_handler(t_data *elem);
void	ft_format_wstr_flags(t_data *elem);
void	ft_format_wstr_precision_handler(t_data *elem);
void	ft_format_wstr_width_handler(t_data *elem);
void	ft_format_wstr_moins_flag_handler(t_data *elem);


void	ft_printer(t_data *elem);
void	ft_print_unicode(t_data *elem);
void	ft_print_null_bite(t_data *elem, int len);
void	ft_print_wchar(t_data *elem);

void	ft_free_structure(t_data **begin_list);

#endif
