/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 08:11:27 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/10 12:55:15 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void			ft_format_point_oct_arg(t_data *elem, va_list ap)
{
	int			base;
	uintmax_t	value;

	value = va_arg(ap, unsigned long int);
	base = (elem->type == 'p') ? 16 : 8;
	elem->neg = 0;
	elem->null = (!value) ? 1 : 0;
	elem->buffer = ft_itoa_base_uintmax(value, base, elem);
}

void			ft_format_hex_modifier(t_data *elem, va_list ap)
{
	int			base;
	uintmax_t	value;
	t_modifier	modifier;

	modifier = elem->modifier;
	base = (elem->type == 'o') ? 8 : 16;
	elem->modifier.l = (modifier.ll) ? 0 : modifier.l;
	elem->modifier.h = (modifier.hh) ? 0 : modifier.h;
	if (modifier.hh)
		value = (unsigned char)va_arg(ap, unsigned int);
	else if (modifier.h)
		value = (unsigned short)va_arg(ap, unsigned int);
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
	elem->neg = 0;
	elem->null = (!value) ? 1 : 0;
	elem->buffer = ft_itoa_base_uintmax(value, base, elem);
}

static void		ft_format_case_modifier(t_data *data)
{
	if (data->type == 'X')
		data->buffer = ft_strtoupper(data->buffer);
}

void			ft_format_hex_router(t_data *elem, int dash)
{
	if (!dash || (dash && (elem->width < (int)ft_strlen(elem->buffer))))
	{
		if (elem->precision > -1)
		{
			ft_format_hex_precision_handler(elem);
			ft_format_hex_precision_width_handler(elem);
		}
		else
			ft_format_hex_width_handler(elem);
	}
	else
	{
		if (elem->precision > -1)
		{
			ft_format_hex_precision_handler(elem);
			ft_format_hex_precision_moins_flag_handler(elem);
		}
		else
			ft_format_hex_moins_flag_handler(elem);
	}
}

void			ft_format_hex(t_data *elem, va_list ap)
{
	int		dash;
	int		hash;
	int		is_octal;

	ft_init_values(elem);
	dash = elem->flags.dash;
	hash = elem->flags.hash;
	is_octal = (elem->type == 'o' || elem->type == 'O') ? 1 : 0;
	(elem->type == 'p' || elem->type == 'O')
		? ft_format_point_oct_arg(elem, ap) : ft_format_hex_modifier(elem, ap);
	elem->flags.hash = (elem->null) ? 0 : elem->flags.hash;
	elem->flags.hash = (!elem->precision && is_octal && hash
		&& elem->width == -1) ? 1 : elem->flags.hash;
	ft_format_hex_router(elem, dash);
	ft_format_hex_null_value(elem);
	ft_format_case_modifier(elem);
}
