/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:06:33 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/06 03:37:19 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include "ft_formatters.h"

# define TYPE_INT_1     'd'
# define TYPE_INT_2     'D'
# define TYPE_INT_3     'i'
# define TYPE_HEX_1	    'x'
# define TYPE_HEX_2	    'X'
# define TYPE_OCT_1     'o'
# define TYPE_OCT_2     'O'
# define TYPE_CHAR_1    'c'
# define TYPE_CHAR_2    'C'
# define TYPE_CHAR_1    'c'
# define TYPE_U_INT_1   'u'
# define TYPE_U_INT_2   'U'
# define TYPE_P_1       'p'
# define TYPE_STR_1     's'
# define TYPE_STR_2     'S'
# define TYPE_PERCENT	'%'

typedef struct	s_fmt_type
{
	char	type;
	void	(*f)(t_data *, va_list);
}				t_fmt_type;

t_fmt_type	g_types[] =
{
	{TYPE_INT_1, &ft_format_int},
	{TYPE_INT_2, &ft_format_int},
	{TYPE_INT_3, &ft_format_int},
	{TYPE_HEX_1, &ft_format_hex},
	{TYPE_HEX_2, &ft_format_hex},
	{TYPE_OCT_1, &ft_format_hex},
	{TYPE_OCT_2, &ft_format_hex},
	{TYPE_CHAR_1, &ft_format_char},
	{TYPE_CHAR_2, &ft_format_char},
	{TYPE_U_INT_1, &ft_format_u_int},
	{TYPE_U_INT_2, &ft_format_u_int},
	{TYPE_P_1, &ft_format_hex},
	{TYPE_STR_1, &ft_format_str},
	{TYPE_STR_2, &ft_format_str},
	{TYPE_PERCENT, &ft_format_percent},
	{0, 0}
};

#endif
