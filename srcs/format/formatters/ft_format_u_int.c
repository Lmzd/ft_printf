/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:39:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/10 12:53:27 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_format_get_u_arg(t_data *elem, va_list ap)
{
	uintmax_t value;

	value = va_arg(ap, unsigned long int);
	elem->null = (!value) ? 1 : 0;
	elem->neg = 0;
	elem->buffer = ft_itoa_base_uintmax(value, 10, elem);
}

void	ft_format_u_int_modifier(t_data *elem, va_list ap)
{
	uintmax_t	value;
	t_modifier	modifier;

	modifier = elem->modifier;
	elem->modifier.l = (modifier.ll) ? 0 : modifier.l;
	elem->modifier.h = (modifier.hh) ? 0 : modifier.h;
	if (modifier.hh)
		value = (unsigned char)va_arg(ap, unsigned int);
	else if (modifier.h)
		value = (unsigned short int)va_arg(ap, unsigned int);
	else if (modifier.ll)
		value = va_arg(ap, unsigned long long int);
	else if (modifier.l)
		value = va_arg(ap, unsigned long int);
	else if (modifier.j)
		value = va_arg(ap, uintmax_t);
	else if (modifier.z)
		value = va_arg(ap, size_t);
	else
		value = va_arg(ap, unsigned int);
	elem->null = (!value) ? 1 : 0;
	elem->neg = 0;
	elem->buffer = ft_itoa_base_uintmax(value, 10, elem);
}

void	ft_format_u_int_minus(t_data *elem)
{
	if (elem->precision > -1)
	{
		ft_format_precision_handler(elem);
		ft_format_precision_moins_flag_handler(elem);
	}
	else
	{
		ft_format_moins_flag_handler(elem);
		ft_format_moins_flag_space_or_plus_handler(elem);
	}
}

void	ft_format_u_int(t_data *elem, va_list ap)
{
	ft_init_values(elem);
	(elem->type == 'U')
		? ft_format_get_u_arg(elem, ap)
		: ft_format_u_int_modifier(elem, ap);
	elem->value = L'\0';
	if (!elem->flags.dash
		|| (elem->flags.dash && (elem->width < (int)ft_strlen(elem->buffer))))
	{
		if (elem->precision > -1)
		{
			ft_format_precision_handler(elem);
			ft_format_precison_width_handler(elem);
		}
		else
		{
			ft_format_width_handler(elem);
			ft_format_plus_flag_handler(elem);
			ft_format_space_flag_handler(elem);
		}
	}
	else
		ft_format_u_int_minus(elem);
	ft_format_null_value(elem);
}
