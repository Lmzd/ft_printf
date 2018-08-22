/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:40:00 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/22 16:56:02 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_format_char_modifier(t_data *elem, va_list ap)
{
	char	*value;

	value = ft_strnew(1);
	elem->modifier.l = (elem->modifier.ll) ? 0 : elem->modifier.l;
	if (elem->modifier.l || elem->type == 'C')
	{
		elem->value = va_arg(ap, wint_t);
		if ((MB_CUR_MAX == 1 && elem->value > 255) || (elem->value > 55295
			&& elem->value < 57344) || elem->value > 1114111 || elem->value < 0)
		{
			elem->error = 1;
			elem->value = NULL;
		}
		elem->null = 0;
	}
	else if (elem->type == 'c')
	{
		value[0] = (unsigned char)va_arg(ap, int);
		elem->null = (value[0] == 0) ? 1 : 0;
	}
	elem->neg = 0;
	elem->buffer = value;
}

void	ft_format_char(t_data *elem, va_list ap)
{
	ft_init_values(elem);
	ft_format_char_modifier(elem, ap);
	if (elem->error)
		return ;
	if (!elem->flags.dash
		|| (elem->flags.dash && (elem->width < (int)ft_strlen(elem->buffer))))
	{
		ft_format_width_handler(elem);
		ft_format_plus_flag_handler(elem);
		ft_format_space_flag_handler(elem);
	}
	else
	{
		ft_format_moins_flag_handler(elem);
		ft_format_moins_flag_space_or_plus_handler(elem);
	}
	ft_format_null_value(elem);
}
