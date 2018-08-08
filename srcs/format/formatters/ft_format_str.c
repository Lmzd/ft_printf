/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:13:25 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:04:35 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"

void	ft_format_str_modifier(t_data *elem, va_list ap)
{
	char	*value;
	wchar_t *val;

	elem->neg = 0;
	if (elem->type == 'S'
		|| (elem->type == 's' && elem->modifier.l && !elem->modifier.ll))
	{
		val = va_arg(ap, wchar_t *);
		elem->null = (!val) ? 1 : 0;
		elem->buffer = (elem->null) ? ft_strdup("(null)") : NULL;
		elem->wmalloc = (elem->null) ? 1 : 0;
		elem->wbuffer = val;
	}
	else if (elem->type == 's')
	{
		value = va_arg(ap, char *);
		elem->null = (!value) ? 1 : 0;
		elem->buffer = (elem->null) ? ft_strdup("(null)") : value;
		elem->wmalloc = (elem->null) ? 1 : 0;
	}
}

void	ft_format_str(t_data *elem, va_list ap)
{
	ft_init_values(elem);
	ft_format_str_modifier(elem, ap);
	if (elem->wbuffer)
		ft_format_wstr_flags(elem);
	else if (elem->buffer)
		ft_format_str_flags(elem);
}
